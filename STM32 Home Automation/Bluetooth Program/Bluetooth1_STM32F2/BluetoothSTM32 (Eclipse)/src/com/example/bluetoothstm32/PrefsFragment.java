package com.example.bluetoothstm32;

import android.os.Bundle;
import android.preference.PreferenceFragment;

public class PrefsFragment extends PreferenceFragment {

 @Override
 public void onCreate(Bundle savedInstanceState) {
  // TODO Auto-generated method stub
  super.onCreate(savedInstanceState);
  
  // Load the preferences from an XML resource
        addPreferencesFromResource(R.xml.pref);
 }

}