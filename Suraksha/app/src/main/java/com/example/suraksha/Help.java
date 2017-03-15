package com.example.suraksha;

import android.app.Fragment;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Toast;


public class Help extends Fragment{
	public View onCreateView(LayoutInflater inflater, ViewGroup container,Bundle savedInstanceState) {
		View rootView = inflater.inflate(R.layout.activity_help, container, false);
		Toast.makeText(getActivity(), "Do not Forget to EditContacts for Message purposes", Toast.LENGTH_LONG).show();
		return rootView;
	}public void onBackPressed() {
		int count = getFragmentManager().getBackStackEntryCount();
		if (count == 0) {
			//super.onBackPressed();
			//additional code
		} else {
			getFragmentManager().popBackStack();
		}
	}
}