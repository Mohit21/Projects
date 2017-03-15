package com.example.suraksha;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
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

public class Register extends Activity {
	private static final String TAG = "Register";
	private static final int REQUEST_SIGNUP = 0;
	Button Reg;
    int OTP=0;
	EditText Name;
	EditText Email;
	EditText Mobile;
	EditText Password;
	EditText Cpassword;
	String name = "", email = "", password = "", mobile1="", cpassword="", mobile="";
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);

		setContentView(R.layout.activity_register);
        Reg = (Button)findViewById(R.id.register1);
        Reg.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View v) {
				signup();
			}
		});
	}

	public void signup() {
        Name = (EditText)findViewById(R.id.name1);
        Email = (EditText)findViewById(R.id.email1);
        Password = (EditText)findViewById(R.id.passwrd1);
        Cpassword = (EditText)findViewById(R.id.cnfrmpasswrd1);
        Mobile = (EditText)findViewById(R.id.mobile1);
        name = Name.getText().toString();
        email = Email.getText().toString();
        password = Password.getText().toString();
        cpassword =Cpassword.getText().toString();
        mobile = Mobile.getText().toString();
        Log.v(TAG, "Register");
		if (validate()==false) {
			onSignupFailed();
			return;
		}
		Reg.setEnabled(false);
		genOtp();
		final String otp=String.valueOf(OTP);
		// TODO: Implement your own signup logic here.
		StringRequest request = new StringRequest(Request.Method.POST,"https://mohit21395.000webhostapp.com/register.php", new Response.Listener<String>() {
			@Override
			public void onResponse(String response) {
				if(response.equals("success")){
					Toast.makeText(Register.this, "Registered Successfully..Please wait for Verification Mail", Toast.LENGTH_LONG).show();
					Intent i=new Intent(Register.this,validEmail.class);
					i.putExtra("Name",name);
					i.putExtra("Email",email);
					i.putExtra("Password",password);
					i.putExtra("Phone",mobile);
					startActivity(i);
				}
				else{
					Toast.makeText(Register.this, response, Toast.LENGTH_LONG).show();
					deleteRecord(email);
				}
			}
		}, new Response.ErrorListener() {
			@Override
			public void onErrorResponse(VolleyError error) {
				Toast.makeText(Register.this, error.getMessage(), Toast.LENGTH_LONG).show();
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
		RequestQueue requestQueue= Volley.newRequestQueue(getApplicationContext());
		requestQueue.add(request);
	}
	@Override
	protected void onActivityResult(int requestCode, int resultCode, Intent data) {
		if (requestCode == REQUEST_SIGNUP) {
			if (resultCode == RESULT_OK) {
				// TODO: Implement successful signup logic here
				// By default we just finish the Activity and log them in automatically
				this.finish();
			}
		}
	}
	public void onSignupSuccess() {
		Reg.setEnabled(true);
		setResult(RESULT_OK, null);
		finish();
	}
	public void onSignupFailed() {
		Toast.makeText(getBaseContext(),"Registration failed", Toast.LENGTH_LONG).show();
		Reg.setEnabled(false);
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
	public void deleteRecord(final String em1){
		StringRequest request = new StringRequest(Request.Method.POST,"https://mohit21395.000webhostapp.com/deleteRecords.php", new Response.Listener<String>() {
			@Override
			public void onResponse(String response) {
				if(response.equals("success")){
					Toast.makeText(Register.this, "Please Register Again", Toast.LENGTH_LONG).show();
					Intent intent=new Intent(Register.this,Register.class);
					startActivity(intent);
				}
				else{
					Toast.makeText(Register.this, response, Toast.LENGTH_LONG).show();
				}
			}
		}, new Response.ErrorListener() {
			@Override
			public void onErrorResponse(VolleyError error) {
				Toast.makeText(Register.this, error.getMessage(), Toast.LENGTH_LONG).show();
				//progressDialog.dismiss();
			}
		}){
			@Override
			protected Map<String, String> getParams() throws AuthFailureError {
				Map<String,String> map=new HashMap<String, String>();
				map.put("v_email",email);
				return map;
			}
		};
		RequestQueue requestQueue= Volley.newRequestQueue(getApplicationContext());
		requestQueue.add(request);
		new android.os.Handler().postDelayed(
				new Runnable() {
					public void run() {
						onSignupSuccess1();
					}
				}, 3000);
	}

	public void onSignupSuccess1() {
		Reg.setEnabled(false);
		setResult(RESULT_OK, null);
		Intent i = new Intent(Register.this,
				Register.class);
		startActivity(i);
		finish();
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