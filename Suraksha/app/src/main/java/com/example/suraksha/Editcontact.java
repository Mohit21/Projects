package com.example.suraksha;


import android.app.Fragment;
import android.content.Context;
import android.content.SharedPreferences;
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

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.HashMap;
import java.util.Map;

import static com.example.suraksha.Login.Emailp;
import static com.example.suraksha.Login.MyPREFERENCES;
import static com.example.suraksha.Login.Namep;
import static com.example.suraksha.Login.Passwordp;
import static com.example.suraksha.Login.Phonep;
import static com.example.suraksha.R.id.contact1;
import static com.example.suraksha.R.id.contact2;
import static com.example.suraksha.R.id.contact3;
import static com.example.suraksha.R.id.contact4;
import static com.example.suraksha.R.id.contact5;
public class Editcontact extends Fragment{
	public Editcontact(){}
	private static final String TAG = "Contact";
	Button get,cont;
	EditText Mob1;
	EditText Mob2;
	EditText Mob3;
	EditText Mob4;
	EditText Mob5;
    Login log;
	String mob1 = "", mob2 = "", mob3 = "", mob4="", mob5="",email1="";
	SharedPreferences sharedpreferences;
	String name = "", email = "", password = "", mobile="";
	public View onCreateView(LayoutInflater inflater, ViewGroup container,Bundle savedInstanceState) {
		View rootView = inflater.inflate(R.layout.activity_contact, container, false);
		cont = (Button)rootView.findViewById(R.id.consubmit);
		Mob1 = (EditText)rootView.findViewById(contact1);
        Mob2 = (EditText)rootView.findViewById(contact2);
        Mob3 = (EditText)rootView.findViewById(contact3);
        Mob4 = (EditText)rootView.findViewById(contact4);
        Mob5 = (EditText)rootView.findViewById(contact5);
		Toast.makeText(getActivity(),"Contacts If added are shown here", Toast.LENGTH_LONG).show();
		sharedpreferences = this.getActivity().getSharedPreferences(MyPREFERENCES, Context.MODE_PRIVATE);
		name = sharedpreferences.getString(Namep,"");
		email = sharedpreferences.getString(Emailp,"");
		password = sharedpreferences.getString(Passwordp,"");
		mobile = sharedpreferences.getString(Phonep,"");
		getData();
		cont.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View v) {
				conSubmit();
			}
		});
        return rootView;
	}

	public void conSubmit() {
        email1=email;
        mob1 = Mob1.getText().toString();
		mob2 = Mob2.getText().toString();
		mob3 = Mob3.getText().toString();
		mob4 = Mob4.getText().toString();
		mob5 = Mob5.getText().toString();
		Log.v(TAG, "Contact");
		if (validate()==false) {
			onContactFailed();
			return;
		}
		// TODO: Implement your own signup logic here.
		StringRequest request = new StringRequest(Request.Method.POST,"https://mohit21395.000webhostapp.com/Contact.php", new Response.Listener<String>() {
			@Override
			public void onResponse(String response) {
				if(response.equals("success")){
                    Toast.makeText(getActivity(),"Contacts Edited", Toast.LENGTH_LONG).show();
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
				map.put("C_eml",email1);
                map.put("C_m1",mob1);
                map.put("C_m2",mob2);
				map.put("C_m3",mob3);
				map.put("C_m4",mob4);
                map.put("C_m5",mob5);
				return map;
			}
		};
		RequestQueue requestQueue= Volley.newRequestQueue(getActivity().getApplicationContext());
		requestQueue.add(request);
	}

	public void onContactFailed() {
		Toast.makeText(getActivity().getBaseContext(), "Editing Failed", Toast.LENGTH_LONG).show();
		cont.setEnabled(true);
	}

	public boolean validate() {
		boolean valid = true;
        if (mob1.isEmpty() || mob1.length() <10 || mob1.length() >10) {
            Mob1.setError("10 Numbered Contact.Do not include state-code");
            valid = false;
        }
        else {
            Mob1.setError(null);
        }

        if (mob2.isEmpty() || mob2.length() <10 || mob2.length() >10) {
            Mob2.setError("10 Numbered Contact.Do not include state-code");
            valid = false;
        }
        else {
            Mob2.setError(null);
        }
        if (mob3.isEmpty() || mob3.length() <10 || mob3.length() >10) {
            Mob3.setError("10 Numbered Contact.Do not include state-code");
            valid = false;
        }
        else {
            Mob3.setError(null);
        }
        if (mob4.isEmpty() || mob4.length() <10 || mob4.length() >10) {
            Mob4.setError("10 Numbered Contact.Do not include state-code");
            valid = false;
        }
        else {
            Mob4.setError(null);
        }
        if (mob5.isEmpty() || mob5.length() <10 || mob5.length() >10) {
            Mob5.setError("10 Numbered Contact.Do not include state-code");
            valid = false;
        }
        else {
            Mob5.setError(null);
        }
		return valid;
	}
    //Json data get
	private void getData() {
		StringRequest stringRequest = new StringRequest(Request.Method.GET,"https://mohit21395.000webhostapp.com/ContactFetch.php?id="+email, new Response.Listener<String>() {
			@Override
			public void onResponse(String response) {
				Toast.makeText(getActivity().getBaseContext(), "Contacts Retrieved", Toast.LENGTH_LONG).show();
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
		String email1="",mob1="",mob2="",mob3="",mob4="",mob5="";
		try {
			JSONObject jsonObject = new JSONObject(response);
			JSONArray result = jsonObject.getJSONArray("result");
			JSONObject Data = result.getJSONObject(0);
			email1=Data.getString("email");
			mob1 = Data.getString("mob11");
			mob2 = Data.getString("mob2");
			mob3 = Data.getString("mob3");
			mob4 = Data.getString("mob4");
			mob5 = Data.getString("mob5");
		} catch (JSONException e) {
			e.printStackTrace();
		}
		Mob1.setText(mob1);
		Mob2.setText(mob2);
		Mob3.setText(mob3);
		Mob4.setText(mob4);
		Mob5.setText(mob5);
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
}