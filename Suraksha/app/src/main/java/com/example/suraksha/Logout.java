package com.example.suraksha;

import android.app.Fragment;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Toast;


public class Logout extends Fragment {
	public Logout(){}
		public View onCreateView(LayoutInflater inflater, ViewGroup container,Bundle savedInstanceState) {
		View rootView = inflater.inflate(R.layout.activity_logout, container, false);
		Toast.makeText(getActivity(), "Hope you felt Safe and Fearless", Toast.LENGTH_LONG).show();
			SharedPreferences sharedpreferences = getActivity().getSharedPreferences(Login.MyPREFERENCES, Context.MODE_PRIVATE);
			SharedPreferences.Editor editor = sharedpreferences.edit();
			editor.clear();
			editor.commit();
			Intent i = new Intent(getActivity(), Login.class);
        	startActivity(i);
			getActivity().finish();
        return rootView;		
	}
}