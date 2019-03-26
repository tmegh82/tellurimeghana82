package ru.driim.bluetoothterminal;

import android.os.AsyncTask;
import android.os.Bundle;
import android.app.Activity;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.view.Menu;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ProgressBar;
import android.widget.Toast;

public class Register extends Activity {

	EditText uname,pass,ag,mail,phone,loc;
	Button register;
	ProgressBar pb;
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_register);
		uname=(EditText)findViewById(R.id.editText1);
		pass=(EditText)findViewById(R.id.editText2);
		ag=(EditText)findViewById(R.id.editText3);
		mail=(EditText)findViewById(R.id.editText4);
		phone=(EditText)findViewById(R.id.editText5);
		loc=(EditText)findViewById(R.id.editText6);
		pb=(ProgressBar)findViewById(R.id.progressBar1);
		register=(Button)findViewById(R.id.button1);
		
		register.setOnClickListener(new OnClickListener(){

			@Override
			public void onClick(View arg0) {
				// TODO Auto-generated method stub
				if(!((uname.getText().toString().equals("")) || (pass.getText().toString().equals("")) || (ag.getText().toString().equals("")) || (mail.getText().toString().equals(""))||(phone.getText().toString().equals(""))||(loc.getText().toString().equals("")))) {
					ActiveTask1 task=new ActiveTask1();
					task.execute();
				}	
				else {
					Toast.makeText(getApplicationContext(), "enter values in all field", Toast.LENGTH_SHORT).show();
				}
			}
			
		});
	}
	
	private class ActiveTask1 extends AsyncTask<String,Void,Void> {
		String username=uname.getText().toString();
		String password=pass.getText().toString();
		String age=ag.getText().toString();
		String emailid=mail.getText().toString();
		String mobile=phone.getText().toString();
		String location=loc.getText().toString();
		String res=null;
		
		protected void onPreExecute() {
			pb.setVisibility(View.VISIBLE);
		}

		
		protected Void doInBackground(String... params) {
			res=CallService.registerService(username,password,age,emailid,mobile,location,"Register");
			return null;
		}
		
		@Override
		protected void onPostExecute(Void result) {
			pb.setVisibility(View.INVISIBLE);
			if(res.equals("success")) {
				AlertDialog.Builder dia=new AlertDialog.Builder(Register.this);
				//dia.setIcon(draw1);
				dia.setTitle("Trust Agent");
				dia.setMessage("account created");	
				dia.setCancelable(false);	
				dia.setPositiveButton("Got it", new DialogInterface.OnClickListener(){
					@Override
					public void onClick(DialogInterface dialog, int which) {					
						Intent intent=new Intent(getBaseContext(),Login.class);
						intent.putExtra("username", username);
						startActivity(intent);
						dialog.cancel();
						
					}				
				});
				AlertDialog dialo=dia.create();
				dialo.show();
			}
			else {
				Toast.makeText(getApplicationContext(), res, Toast.LENGTH_SHORT).show();
			}
			
		}
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.register, menu);
		return true;
	}

}
