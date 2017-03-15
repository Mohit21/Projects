package com.example.suraksha;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.os.Handler;
import android.view.View;
import android.view.animation.AlphaAnimation;
import android.view.animation.TranslateAnimation;
import android.widget.ImageView;
import android.widget.TextView;

import static com.example.suraksha.Login.MyPREFERENCES;
import static com.example.suraksha.Login.flg;


public class Splash extends Activity{
	ImageView imageview;
	TextView textview;
	SharedPreferences sharedpreferences;
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_splash);
		/*
		IntentFilter filter = new IntentFilter(Intent.ACTION_SCREEN_ON);
		filter.addAction(Intent.ACTION_SCREEN_OFF);
		Panicbutton mReceiver = new Panicbutton (this);
		registerReceiver(mReceiver, filter);
		getActionBar().hide();
		getWindow().addFlags(WindowManager.LayoutParams.FLAG_DISMISS_KEYGUARD);
		*/
		imageview = (ImageView) findViewById(R.id.imageView1);
		textview = (TextView) findViewById(R.id.textView1);
		sharedpreferences = getSharedPreferences(MyPREFERENCES, Context.MODE_PRIVATE);
		if(isLoggedIn()){
			Intent intent=new Intent(Splash.this,MainActivity1.class);
			startActivity(intent);
			finish();
		}
		else{
			imageview.setVisibility(View.VISIBLE);
			TranslateAnimation slide = new TranslateAnimation(0, 0, 100,0);
			slide.setDuration(6000);
			slide.setFillAfter(true);
			imageview.startAnimation(slide);

			AlphaAnimation anim = new AlphaAnimation(0.1f, 1.0f);
			anim.setDuration(5000);
			textview.startAnimation(anim);
			new Handler().postDelayed(new Runnable() {

				@Override
				public void run() {
					Intent i = new Intent(Splash.this,
							Login.class);
					startActivity(i);
					Splash.this.finish();
				}
			},7000);
		}
	}
	public boolean isLoggedIn(){
		return sharedpreferences.getBoolean(flg, false);
	}
}
