package com.example.suraksha;


import android.app.Fragment;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.android.volley.AuthFailureError;
import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.VolleyError;
import com.android.volley.toolbox.StringRequest;
import com.android.volley.toolbox.Volley;

import java.util.HashMap;
import java.util.Map;
import java.util.Random;


public class Update extends Fragment {
	public Update(){}
	private static final String TAG = "Update";
	private static final int REQUEST_SIGNUP = 0;
	Button Reg;
	EditText Name;
	EditText Email;
	EditText Mobile;
	EditText Password;
	EditText Cpassword;
	int OTP=0;
	String name = "", email = "", password = "",otp="", cpassword="", mobile="";

	public View onCreateView(LayoutInflater inflater, ViewGroup container,Bundle savedInstanceState) {
		View rootView = inflater.inflate(R.layout.activity_update, container, false);

		Reg = (Button)rootView.findViewById(R.id.uregister1);
		Name = (EditText)rootView.findViewById(R.id.uname1);
		Email = (EditText)rootView.findViewById(R.id.uemail1);
		Password = (EditText)rootView.findViewById(R.id.upasswrd1);
		Cpassword = (EditText)rootView.findViewById(R.id.ucnfrmpasswrd1);
		Mobile = (EditText)rootView.findViewById(R.id.umobile1);
		Reg.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View v) {
				update();
			}
		});
        return rootView;
	}

	public void update() {
		name = Name.getText().toString();
		email = Email.getText().toString();
		password = Password.getText().toString();
		cpassword =Cpassword.getText().toString();
		mobile = Mobile.getText().toString();
		Log.v(TAG, "Update");
		if (validate()==false) {
			updateFailed();
			return;
		}
		genOtp();
		otp=String.valueOf(OTP);
		//Register.setEnabled(false);
		// TODO: Implement your own signup logic here.
		StringRequest request = new StringRequest(Request.Method.POST,"https://mohit21395.000webhostapp.com/UpdatePInfo.php", new Response.Listener<String>() {
			@Override
			public void onResponse(String response) {
				if(response.equals("success")){
					Toast.makeText(getActivity(), "Verification Successful", Toast.LENGTH_LONG).show();
					Intent i=new Intent(getActivity(),validEmail.class);
					startActivity(i);
				}
				else{
					Toast.makeText(getActivity(), response, Toast.LENGTH_LONG).show();
				}
			}
		}, new Response.ErrorListener() {
			@Override
			public void onErrorResponse(VolleyError error) {
				Toast.makeText(getActivity(), error.getMessage(), Toast.LENGTH_LONG).show();
			}
		}){
			@Override
			protected Map<String, String> getParams() throws AuthFailureError {
				Map<String,String> map=new HashMap<String, String>();
				map.put("P_nm",name);
				map.put("P_eml",email);
				map.put("P_pwd",password);
				map.put("P_mob",mobile);
				map.put("P_otp",otp);
				return map;
			}
		};
		RequestQueue requestQueue= Volley.newRequestQueue(getActivity().getApplicationContext());
		requestQueue.add(request);
	}

	public void onSignupSuccess() {
		Reg.setEnabled(true);
		//setResult(RESULT_OK, null);
		//finish();
	}

	public void updateFailed() {
		Toast.makeText(getActivity().getBaseContext(), "Registration failed", Toast.LENGTH_LONG).show();
		Reg.setEnabled(true);
	}

	public boolean validate() {
		boolean valid = true;
		if (name.isEmpty() || name.length() < 3) {

			Name.setError("At least 3 characters");
			valid = false;
		} else {
			Name.setError(null);
		}

		if (email.isEmpty() || !android.util.Patterns.EMAIL_ADDRESS.matcher(email).matches()) {
			Email.setError("Enter a valid Email Address");
			valid = false;
		}
		else {
			Email.setError(null);
		}

		if (password.isEmpty() || password.length() < 5 || password.length() > 20) {
			Password.setError("The Password should be between 6 and 20 Alphanumeric Characters");
			valid = false;
		}

		else {
			Password.setError(null);
		}

		if (cpassword.isEmpty() || cpassword.length() < 5 || cpassword.length() > 20 || !(cpassword.equals(password))) {
			Cpassword.setError("Passwords do not Match.Please Enter the same as in Password");
			valid = false;
		}
		else {
			Cpassword.setError(null);
		}

		if (mobile.isEmpty() || mobile.length() <10 || mobile.length() >10) {
			Mobile.setError("10 Numbered Contact.Do not include state-code");
			valid = false;
		}
		else {
			Mobile.setError(null);
		}
		return valid;
	}
	public void onBackPressed() {
		int count = getFragmentManager().getBackStackEntryCount();
		if (count == 0) {
			//super.onBackPressed();
			//additional code
		} else {
			getFragmentManager().popBackStack();
		}
	}
    public void genOtp(){
        int digits=7;
        int max = (int) Math.pow(10,(digits)) - 1; //for digits =7, max will be 9999999
        int min = (int) Math.pow(10, digits-1); //for digits = 7, min will be 1000000
        int range = max-min; //This is 8999999
        Random r = new Random();
        int x = r.nextInt(range);// This will generate random integers in range 0 - 8999999
        int nDigitRandomNo = x+min; //Our random rumber will be any random number x + min
		OTP=nDigitRandomNo;
    }
}