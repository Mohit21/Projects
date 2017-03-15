package com.example.suraksha;

import android.app.AlertDialog;
import android.app.Fragment;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;


public class Main extends Fragment{

	SharedPreferences sharedpreferences;
	public View onCreateView(LayoutInflater inflater, ViewGroup container,Bundle savedInstanceState) {

		/*
		PowerManager mgr = (PowerManager)getActivity().getSystemService(Context.POWER_SERVICE);
		PowerManager.WakeLock wakeLock = mgr.newWakeLock(PowerManager.PARTIAL_WAKE_LOCK,"MyWakeLock");
		wakeLock.acquire(1000);
		*/
		View rootView = inflater.inflate(R.layout.activity_main, container, false);
		Button btnShowLocation;
		//String email1="";
		btnShowLocation = (Button) rootView.findViewById(R.id.button1);
		btnShowLocation.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View v) {
				Intent intent = new Intent(getActivity(), MapsActivity.class);
				//intent.putExtra(email1);
				startActivity(intent);
				//getActivity().finish();
			}
		});
		return rootView;
	}

	public void onBackPressed() {
		new AlertDialog.Builder(getActivity())
				.setTitle("Back Disabled?")
				.setMessage("Back button is disbaled...Please use Navigation Drawer to proceed")
				.setNegativeButton(android.R.string.no, null)
				.setPositiveButton(android.R.string.yes,null).create().show();
	}
}