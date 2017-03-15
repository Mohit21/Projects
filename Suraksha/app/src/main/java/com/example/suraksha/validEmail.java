package com.example.suraksha;

import android.app.Activity;
import android.app.AlertDialog;
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

public class validEmail extends Activity implements View.OnClickListener {
    private static final String TAG = "validEmail";
    EditText Vecode,Vmcode;
    Button Submit;
    String OTP="";
    String vecode = "",vmcode="",Email="",password="",name="",mobile="",mob1="8700903421";
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_validemail);
        Bundle bundle = getIntent().getExtras();
        name = bundle.getString("Name");
        Email = bundle.getString("Email");
        password = bundle.getString("Password");
        mobile = bundle.getString("Phone");
        OTP   = bundle.getString("OTP1");
        //Toast.makeText(validEmail.this, "R....."+ OTP, Toast.LENGTH_LONG).show();

        Submit = (Button) findViewById(R.id.submit);
        Submit.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                check1(Email);
            }
        });
    }

    public void check1(final String em) {
        Vecode = (EditText) findViewById(R.id.code);
        //Vmcode = (EditText) findViewById(R.id.code1);
        vecode = Vecode.getText().toString();
        //vmcode = Vmcode.getText().toString();
        Log.d(TAG, "validEmail");
        Submit.setEnabled(false);
        //sendmessage();

        StringRequest request = new StringRequest(Request.Method.POST,"https://mohit21395.000webhostapp.com/verifyEmail.php", new Response.Listener<String>() {
            @Override
            public void onResponse(String response) {
                if(response.equals("success")){
                    Toast.makeText(validEmail.this,"Verification is Successful...Please Login", Toast.LENGTH_LONG).show();
                    Intent intent=new Intent(validEmail.this,Login.class);
                    intent.putExtra("Name",name);
                    intent.putExtra("Email",Email);
                    intent.putExtra("Password",password);
                    intent.putExtra("Phone",mobile);
                    startActivity(intent);
                }
                else{
                    Toast.makeText(validEmail.this, response, Toast.LENGTH_LONG).show();
                    Toast.makeText(validEmail.this, "Enter an Email and Mobile that exists", Toast.LENGTH_LONG).show();
                    deleteRecord(em);
                }
            }
        }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError error) {
                Toast.makeText(validEmail.this, error.getMessage(), Toast.LENGTH_LONG).show();

                //progressDialog.dismiss();
            }
        }){
            @Override
            protected Map<String, String> getParams() throws AuthFailureError {
                Map<String,String> map=new HashMap<String, String>();
                map.put("v_email",Email);
                map.put("vecode",vecode);
                //map.put("vmcode",vmcode);
                //map.put("vmcode1",OTP);
                return map;
            }
        };

        RequestQueue requestQueue= Volley.newRequestQueue(getApplicationContext());
        requestQueue.add(request);

        new android.os.Handler().postDelayed(
                new Runnable() {
                    public void run() {
                        // On complete call either onLoginSuccess or onLoginFailed
                        onLoginSuccess();
                        // onLoginFailed();
                        //progressDialog.dismiss();
                    }
                }, 3000);
    }
/*
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
*/
    public void onLoginSuccess() {
        //Loginobj.setEnabled(true);
        finish();
    }

    @Override
    public void onClick(View v) {

    }
    public void deleteRecord(final String em1){
        StringRequest request = new StringRequest(Request.Method.POST,"https://mohit21395.000webhostapp.com/deleteRecords.php", new Response.Listener<String>() {
                @Override
                public void onResponse(String response) {
                    if(response.equals("success")){
                        Toast.makeText(validEmail.this, "Please Register Again", Toast.LENGTH_LONG).show();
                        Intent intent=new Intent(validEmail.this,Register.class);
                        startActivity(intent);
                        //
                    }
                    else{
                        Toast.makeText(validEmail.this, response, Toast.LENGTH_LONG).show();
                        //progressDialog.dismiss();
                    }
                }
            }, new Response.ErrorListener() {
                @Override
                public void onErrorResponse(VolleyError error) {
                    Toast.makeText(validEmail.this, error.getMessage(), Toast.LENGTH_LONG).show();
                    //progressDialog.dismiss();
                }
            }){
                @Override
                protected Map<String, String> getParams() throws AuthFailureError {
                    Map<String,String> map=new HashMap<String, String>();
                    map.put("v_email",Email);
                    return map;
                }
            };

            RequestQueue requestQueue= Volley.newRequestQueue(getApplicationContext());
            requestQueue.add(request);

            new android.os.Handler().postDelayed(
                    new Runnable() {
                        public void run() {
                            // On complete call either onLoginSuccess or onLoginFailed
                            onLoginSuccess();
                            // onLoginFailed();
                            //progressDialog.dismiss();
                        }
                    }, 3000);
        }
    public void onBackPressed() {
        new AlertDialog.Builder(this)
                .setTitle("Back Disabled?")
                .setMessage("Back button is disbaled...Please enter the Veritification code")
                .setNegativeButton(android.R.string.no, null)
                .setPositiveButton(android.R.string.yes,null).create().show();
    }
}