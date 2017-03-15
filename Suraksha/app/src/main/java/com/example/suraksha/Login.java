package com.example.suraksha;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
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

public class Login extends Activity implements OnClickListener {
    private static final String TAG = "Login";
    private static final int REQUEST_SIGNIN = 0;

    public static final String MyPREFERENCES = "MyPrefs" ;
    public static final String Emailp = "emailKey";
    public static final String Passwordp = "password";
    public static final String Namep = "name";
    public static final String Phonep = "phone";

    public static final String flg ="false";
    SharedPreferences sharedpreferences;
    EditText Email;
	EditText Password;
	TextView Register;
	TextView Fpasswrd;
	Button Loginobj;
    String email="" , password="",namel="",mobilel="",emaill="",passwordl="";
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_login);
        //HashMap<String, String> user = session.getUserDetails();
        Loginobj = (Button) findViewById(R.id.Login1);
        Register = (TextView)findViewById(R.id.textView1);
		Fpasswrd = (TextView)findViewById(R.id.fpassword);
		Toast.makeText(Login.this, "Keep your Internet Connection on", Toast.LENGTH_LONG).show();
		sharedpreferences = getSharedPreferences(MyPREFERENCES, Context.MODE_PRIVATE);
       /* if(isLoggedIn()){
            Intent intent=new Intent(Login.this,MainActivity.class);
            startActivity(intent);
            finish();
        }*/
        Fpasswrd.setOnClickListener(new OnClickListener() {

			@Override
			public void onClick(View v) {
				Intent i = new Intent(Login.this,
						ForgotPassword.class);
				startActivity(i);
			}
		});

		Register.setOnClickListener(new OnClickListener() {
		@Override
		public void onClick(View v) {
			Intent i = new Intent(Login.this,
					Register.class);
			startActivity(i);
		}
	});
        Loginobj.setOnClickListener(new View.OnClickListener() {
            @Override
			public void onClick(View v) {
				login();
			}
		});
	}
    /*public boolean isLoggedIn(){
        return sharedpreferences.getBoolean(flg, false);
    }*/

	public void login() {
        Email = (EditText) findViewById(R.id.user);
        Password = (EditText) findViewById(R.id.password);
        email = Email.getText().toString();
        password = Password.getText().toString();

        Log.d(TAG, "Login");
		if (validate()==false) {
			onLoginFailed();
			return;
		}

		Loginobj.setEnabled(false);

		StringRequest request = new StringRequest(Request.Method.POST,"https://mohit21395.000webhostapp.com/login.php", new Response.Listener<String>() {
			@Override
			public void onResponse(String response) {
				if(response.equals("success")){
                    SharedPreferences.Editor editor = sharedpreferences.edit();
                    editor.putString(Emailp, email);
                    editor.putString(Passwordp, password);
                    editor.putString(Namep, namel);
                    editor.putString(Phonep, mobilel);
                    editor.putBoolean(flg, true);
                    editor.commit();
                    Toast.makeText(Login.this, "Login Successfully", Toast.LENGTH_LONG).show();
                    Intent intent=new Intent(Login.this,Welcome.class);
					startActivity(intent);
                }
				else{
					Toast.makeText(Login.this, response, Toast.LENGTH_LONG).show();
				}
			}
		}, new Response.ErrorListener() {
			@Override
			public void onErrorResponse(VolleyError error) {
				Toast.makeText(Login.this, error.getMessage(), Toast.LENGTH_LONG).show();
				//progressDialog.dismiss();
			}
		}){
			@Override
			protected Map<String, String> getParams() throws AuthFailureError {
				Map<String,String> map=new HashMap<String, String>();
				map.put("login_username",email);
				map.put("login_password",password);
				return map;
			}
		};

		RequestQueue requestQueue= Volley.newRequestQueue(getApplicationContext());
		requestQueue.add(request);

		new android.os.Handler().postDelayed(
				new Runnable() {
					public void run() {
						onLoginSuccess();
					}
				}, 5000);
	}

	@Override
	protected void onActivityResult(int requestCode, int resultCode, Intent data) {
		if (requestCode == REQUEST_SIGNIN) {
			if (resultCode == RESULT_OK) {
				// TODO: Implement successful signup logic here
				// By default we just finish the Activity and log them in automatically
				this.finish();
			}
		}
	}

	public void onLoginSuccess() {
		finish();
	}

	public void onLoginFailed() {
		Toast.makeText(getBaseContext(), "Login failed", Toast.LENGTH_LONG).show();

		Loginobj.setEnabled(true);
	}

	public boolean validate() {
		boolean valid = true;
		if (email.isEmpty() || !android.util.Patterns.EMAIL_ADDRESS.matcher(email).matches()) {
			Email.setError("Enter a valid Email Address");
			valid = false;
		} else {
			Email.setError(null);
		}

		if (password.isEmpty() || password.length() < 5 || password.length() > 20) {
			Password.setError("Between 6 and 20 alphanumeric characters");
			valid = false;
		} else {
			Password.setError(null);
		}
		return valid;
	}
	@Override
	protected void onPause() {
		// TODO Auto-generated method stub
		super.onPause();
		finish();
	}

    @Override
    public void onClick(View v) {

    }
    @Override
	public void onBackPressed() {
		int count = getFragmentManager().getBackStackEntryCount();
		if (count == 0) {
			//super.onBackPressed();
			//additional code
		} else {
			getFragmentManager().popBackStack();
		}
	}
}
