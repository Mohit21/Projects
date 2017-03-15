package com.example.suraksha;

import android.app.Activity;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.util.Log;
import android.view.WindowManager;
import android.widget.Toast;

public class Panicbutton extends BroadcastReceiver {
    static int countPowerOff = 0;
    private Activity activity = null;
    public Panicbutton(Activity activity) {
        this.activity = activity;
    }
    @Override
    public void onReceive(Context context, Intent intent) {
        Log.v("onReceive", "Power button is pressed.");
        Toast.makeText(context, "power button clicked!!!", Toast.LENGTH_LONG).show();
        if (intent.getAction().equals(Intent.ACTION_SCREEN_OFF)) {
            countPowerOff++;
        } else {
            if (intent.getAction().equals(Intent.ACTION_SCREEN_ON)) {
                if (countPowerOff == 3) {
                    Toast.makeText(context, "hahahahahha!!!", Toast.LENGTH_LONG).show();
                    Intent i = new Intent(activity, Splash.class);
                    i.setClass(context,Splash.class);
                    i.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
                    i.addFlags(WindowManager.LayoutParams.FLAG_SHOW_WHEN_LOCKED +
                            WindowManager.LayoutParams.FLAG_DISMISS_KEYGUARD +
                            WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON +
                            WindowManager.LayoutParams.FLAG_TURN_SCREEN_ON);
                    activity.startActivity(i);
                }
            }
        }
    }
}