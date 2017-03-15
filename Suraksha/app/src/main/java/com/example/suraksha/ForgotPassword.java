package com.example.suraksha;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
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

public class ForgotPassword extends Activity {
    EditText fpmail;
    String fopmail="",email1="";
    Button Fpasswrd;
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_forgotpassword);
        fpmail=(EditText)findViewById(R.id.Fpmail);
        Fpasswrd = (Button)findViewById(R.id.fLogin1);

        Fpasswrd.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View v) {
                //sendEmail();
                forgotPassword();
            }
        });
    }

    /*
    //Send Email from Activity
    protected void sendEmail() {
        Log.i(TAG, "Send email");
        String[] TO = {"mohitkumra95@gmail.com"};
        String[] CC = {""};
        Intent emailIntent = new Intent(Intent.ACTION_SEND);

        emailIntent.setData(Uri.parse("mailto:"));
        emailIntent.setType("text/plain");
        emailIntent.putExtra(Intent.EXTRA_EMAIL, TO);
        emailIntent.putExtra(Intent.EXTRA_CC, CC);
        emailIntent.putExtra(Intent.EXTRA_SUBJECT, "Hello");
        emailIntent.putExtra(Intent.EXTRA_TEXT, "Email message goes here.Wassup");

        try {
            startActivity(Intent.createChooser(emailIntent, "Send mail..."));
            finish();
            //Log.i("Finished sending email...", "");
        } catch (android.content.ActivityNotFoundException ex) {
            Toast.makeText(ForgotPassword.this, "There is no email client installed.", Toast.LENGTH_SHORT).show();
        }
    }
*/
    public void forgotPassword() {
        //Log.v(TAG, "");
        fopmail = fpmail.getText().toString();
        if (validate()==false) {
            ForgotFailed();
            return;
        }
        //Register.setEnabled(false);
        // TODO: Implement your own signup logic here.
        StringRequest request = new StringRequest(Request.Method.POST,"https://mohit21395.000webhostapp.com/ForgotPassword.php", new Response.Listener<String>() {
            @Override
            public void onResponse(String response) {
                if(response.equals("success")){
                    Toast.makeText(ForgotPassword.this, "Registered User...Please Check your Email for the Password.", Toast.LENGTH_LONG).show();
                    //progressDialog.dismiss();
                    //Intent i=new Intent(ForgotPassword.this,Login.class);
                    //startActivity(i);
                }
                else{
                    Toast.makeText(ForgotPassword.this, response, Toast.LENGTH_LONG).show();
                    Intent i=new Intent(ForgotPassword.this,Register.class);
                    startActivity(i);
                    //progressDialog.dismiss();
                }
            }
        }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError error) {
                Toast.makeText(ForgotPassword.this, error.getMessage(), Toast.LENGTH_LONG).show();
                //progressDialog.dismiss();
            }
        }){
            @Override
            protected Map<String, String> getParams() throws AuthFailureError {
                Map<String,String> map=new HashMap<String, String>();
                map.put("F_eml",fopmail);
                return map;
            }
        };
        RequestQueue requestQueue= Volley.newRequestQueue(getApplicationContext());
        requestQueue.add(request);
    }

    public void onSignupSuccess() {
        Fpasswrd.setEnabled(true);
        //setResult(RESULT_OK, null);
        //finish();
    }

    public void ForgotFailed() {
        Toast.makeText(getBaseContext(), "Do not have an Account...Please Register", Toast.LENGTH_LONG).show();
        Fpasswrd.setEnabled(true);
    }

    public boolean validate() {
        boolean valid = true;
        if (fopmail.isEmpty() || !android.util.Patterns.EMAIL_ADDRESS.matcher(fopmail).matches()) {
            //Toast.makeText(getApplicationContext(), "Enter a valid Emal Address.",
            //		Toast.LENGTH_LONG).show();
            //Email.setFocusable(true);
            fpmail.setError("Enter a valid Email Address");
            valid = false;
        }
        else {
            fpmail.setError(null);
        }
        return valid;
    }
}