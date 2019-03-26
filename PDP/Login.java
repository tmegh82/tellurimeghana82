package ru.driim.bluetoothterminal;

import android.os.AsyncTask;
import android.os.Bundle;
import android.app.Activity;
import android.content.Intent;
import android.view.Menu;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ProgressBar;
import android.widget.Toast;

public class Login extends Activity {

	EditText uname,pass;
	Button reg,login;
	ProgressBar mainpb;
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_login);
		uname=(EditText)findViewById(R.id.editText1);
		pass=(EditText)findViewById(R.id.editText2);
		mainpb=(ProgressBar)findViewById(R.id.progressBar1);
		login=(Button)findViewById(R.id.button1);
		reg=(Button)findViewById(R.id.button2);
		
		login.setOnClickListener(new OnClickListener(){

			@Override
			public void onClick(View arg0) {
				// TODO Auto-generated method stub
				if(!((uname.getText().toString().equals("")) || (pass.getText().toString().equals("")))) {
					ActiveTask task=new ActiveTask();
					task.execute();
				}	
				else {
					Toast.makeText(getApplicationContext(), "enter values in all field", Toast.LENGTH_SHORT).show();
				}
			}
			
		});
		
		reg.setOnClickListener(new OnClickListener(){

			@Override
			public void onClick(View arg0) {
				// TODO Auto-generated method stub
				Intent inn=new Intent(getApplicationContext(),Register.class);
				startActivity(inn);
			}
			
		});
		
	}
	
private class ActiveTask extends AsyncTask<String,Void,Void> {
		
		String username=uname.getText().toString();
		String password=pass.getText().toString();
		String res=null;
		
		protected void onPreExecute() {
			mainpb.setVisibility(View.VISIBLE);
		}

		
		protected Void doInBackground(String... params) {
			res=CallService.loginService(username,password,"Login");	
			
			return null;
		}
		
		@Override
		protected void onPostExecute(Void result) {
			
			if(res.equals("success")) {			
			Intent intent=new Intent(getBaseContext(),MainActivity.class);
			intent.putExtra("username", username);
			startActivity(intent);
			}
			else {
				Toast.makeText(getApplicationContext(), res, Toast.LENGTH_SHORT).show();
			}
			mainpb.setVisibility(View.INVISIBLE);
		}
    }

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.login, menu);
		return true;
	}

}
