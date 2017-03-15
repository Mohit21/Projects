package com.example.suraksha;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;


public class Welcome extends Activity{
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_welcome);
		Button got;
		Toast.makeText(Welcome.this, "Allow Permissions for the App in the Settings->Apps", Toast.LENGTH_LONG).show();
		got = (Button)findViewById(R.id.wgot);
		got.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View v) {
				Intent intent = new Intent(Welcome.this,MainActivity.class);
				startActivity(intent);
                finish();
			}
		});
	}
    @Override
    public void onBackPressed() {
        new AlertDialog.Builder(this)
                .setTitle("Logged In")
                .setMessage("End the LoggedIn Session?")
                .setNegativeButton(android.R.string.no, null)
                .setPositiveButton(android.R.string.yes, new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface arg0, int arg1) {
                        Intent intent = new Intent(Welcome.this,Logout.class);
                        startActivity(intent);
                        finish();
                    }
                }).create().show();
    }
}