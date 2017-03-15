package com.example.suraksha;


import android.app.Fragment;
import android.content.Context;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.SimpleAdapter;
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

import java.util.ArrayList;
import java.util.HashMap;

import static com.example.suraksha.Login.Emailp;
import static com.example.suraksha.Login.MyPREFERENCES;
import static com.example.suraksha.Login.Namep;
import static com.example.suraksha.Login.Passwordp;
import static com.example.suraksha.Login.Phonep;

public class History extends Fragment {
    SharedPreferences sharedpreferences;
    String name = "", email = "", password = "", mobile1="", cpassword="", mobile="";
    String locname,loc;
    ListView list;
    ArrayList<HashMap<String, String>> personList;
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
            Bundle savedInstanceState) {

        View rootView = inflater.inflate(R.layout.activity_history, container, false);
        Toast.makeText(getActivity(), "Do not Forget to EditContacts for Message purposes", Toast.LENGTH_LONG).show();
        sharedpreferences = this.getActivity().getSharedPreferences(MyPREFERENCES, Context.MODE_PRIVATE);
        name = sharedpreferences.getString(Namep,"");
        email = sharedpreferences.getString(Emailp,"");
        password = sharedpreferences.getString(Passwordp,"");
        mobile = sharedpreferences.getString(Phonep,"");


        list = (ListView)rootView.findViewById(R.id.listView);
        personList = new ArrayList<HashMap<String,String>>();
        getData();
        return rootView;

	}
    //Json data get
    private void getData() {
		/*
		if (id.equals("")) {
			Toast.makeText(this, "Please enter an id", Toast.LENGTH_LONG).show();
			return;
		}*/
        //String url = Config1.DATA_URL+email;
        //Toast.makeText(getActivity().getBaseContext(), "Response!! jajaja  "+url, Toast.LENGTH_LONG).show();

        StringRequest stringRequest = new StringRequest(Request.Method.GET,"https://mohit21395.000webhostapp.com/LocationFetch.php?id="+email, new Response.Listener<String>() {
            @Override
            public void onResponse(String response) {
                //loading.dismiss();
                Toast.makeText(getActivity().getBaseContext(), "Vulnerable Location", Toast.LENGTH_LONG).show();
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
        //Toast.makeText(getActivity().getBaseContext(), "show data!!", Toast.LENGTH_LONG).show();
        String name1="",id="",address="";
        try {
            JSONObject jsonObject = new JSONObject(response);
            JSONArray peoples = jsonObject.getJSONArray("result");
            for (int i = 0; i < peoples.length(); i++) {
                JSONObject c = peoples.getJSONObject(i);
                id = c.getString("email");
                name1 = c.getString("locname");
                address = c.getString("loc");
                HashMap<String, String> persons = new HashMap<String, String>();
                name1 = address + "\n" + name1;
                persons.put("loc", name1);
                personList.add(persons);
                //Toast.makeText(getActivity().getBaseContext(), "!! " + name1, Toast.LENGTH_LONG).show();
                //Toast.makeText(getActivity().getBaseContext(), "!! " + address, Toast.LENGTH_LONG).show();

                ListAdapter adapter = new SimpleAdapter(
                    getActivity(), personList, R.layout.activity_list_item,
                    new String[]{"loc"},
                    new int[]{R.id.loc}
            );
            list.setAdapter(adapter);
        }
        } catch (JSONException e) {
            e.printStackTrace();
        }

        /*
        Mob1.setText(mob1);
        Mob2.setText(mob2);
        Mob3.setText(mob3);
        Mob4.setText(mob4);
        Mob5.setText(mob5);
        */
        //textViewResult.setText("Name:\t"+name+"\nAddress:\t" +address+ "\nVice Chancellor:\t"+ vc);
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