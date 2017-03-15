package com.example.suraksha;


import android.app.Fragment;
import android.content.Context;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.TextView;
import android.widget.Toast;

import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.VolleyError;
import com.android.volley.toolbox.StringRequest;
import com.android.volley.toolbox.Volley;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import static com.example.suraksha.Login.Emailp;
import static com.example.suraksha.Login.MyPREFERENCES;
import static com.example.suraksha.Login.Namep;
import static com.example.suraksha.Login.Passwordp;
import static com.example.suraksha.Login.Phonep;

public class Settings extends Fragment{
	public Settings(){}
	private RadioGroup radioGrp;
	private RadioButton radioButton;
    Button update,main1;
    TextView Name;
    TextView Email;
    TextView Mobile;
    TextView Password;
    TextView text;
    String name = "", email = "", password = "", mobile="";
    SharedPreferences sharedpreferences;
    int flag=-1;
    MainActivity m1;

    public View onCreateView(LayoutInflater inflater, ViewGroup container,Bundle savedInstanceState) {
        View rootView = inflater.inflate(R.layout.activity_settings, container, false);

        Name = (TextView)rootView.findViewById(R.id.sname);
        Email = (TextView)rootView.findViewById(R.id.semail);
        Password = (TextView)rootView.findViewById(R.id.spassword);
        Mobile = (TextView)rootView.findViewById(R.id.smobile);
        Toast.makeText(getActivity(), "Do not Forget to EditContacts for Message purposes", Toast.LENGTH_LONG).show();
        sharedpreferences = this.getActivity().getSharedPreferences(MyPREFERENCES, Context.MODE_PRIVATE);
        name = sharedpreferences.getString(Namep,"");
        email = sharedpreferences.getString(Emailp,"");
        password = sharedpreferences.getString(Passwordp,"");
        mobile = sharedpreferences.getString(Phonep,"");
        getData();
        text = (TextView)rootView.findViewById(R.id.text1);
        /*
        update = (Button) rootView.findViewById(R.id.supdate);
        main1 = (Button) rootView.findViewById(R.id.smain);

        update.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                MainActivity ma=new MainActivity();
                ma.displayView(6);
                //getActivity().finish();
            }
        });
        main1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                MainActivity ma=new MainActivity();
                ma.displayView(2);
                //getActivity().finish();

            }
        });*/
		return rootView;
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
    //Json data get
    private void getData() {
		StringRequest stringRequest = new StringRequest(Request.Method.GET,"https://mohit21395.000webhostapp.com/PersonalInfoFetch.php?id="+email, new Response.Listener<String>() {
            @Override
            public void onResponse(String response) {
                //loading.dismiss();
                //Toast.makeText(getActivity(),"Settings Synced" + response,Toast.LENGTH_LONG).show();
                showJSON(response);
            }
        },
                new Response.ErrorListener() {
                    @Override
                    public void onErrorResponse(VolleyError error) {
                        Toast.makeText(getActivity(),error.getMessage().toString(),Toast.LENGTH_LONG).show();
                    }
                });

        RequestQueue requestQueue = Volley.newRequestQueue(getActivity().getApplicationContext());
        requestQueue.add(stringRequest);
    }

    //Json data show
    private void showJSON(String response){
        String password1="";
        try {
            JSONObject jsonObject = new JSONObject(response);
            JSONArray result = jsonObject.getJSONArray("result");
            JSONObject Data = result.getJSONObject(0);
            name =Data.getString("name");
            email = Data.getString("email");
            password1 = Data.getString("password");
            mobile = Data.getString("mobile");
        } catch (JSONException e) {
            e.printStackTrace();
        }
        Name.setText(name);
        Email.setText(email);
        Password.setText(password);
        Mobile.setText(mobile);
    }

}