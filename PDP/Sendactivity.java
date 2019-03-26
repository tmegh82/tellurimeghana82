package ru.driim.bluetoothterminal;


import android.os.AsyncTask;
import android.os.Bundle;
import android.app.Activity;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.telephony.gsm.SmsManager;
import android.view.Menu;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ProgressBar;
import android.widget.TextView;
import android.widget.Toast;

public class Sendactivity extends Activity {

	TextView tempra,press;
	EditText mobile;
	Button sendd;
	ProgressBar pbar;
	String temprature,pressure=null;
	String username;
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_sendactivity);
		mobile=(EditText)findViewById(R.id.editText1);
		//pass=(EditText)findViewById(R.id.editText2);
		tempra=(TextView)findViewById(R.id.textView1);
		press=(TextView)findViewById(R.id.textView2);
		sendd=(Button)findViewById(R.id.button1);
		pbar = (ProgressBar)findViewById(R.id.progressBar1);
		temprature = getIntent().getStringExtra("temprature");
		pressure=getIntent().getStringExtra("pressure");
		username=getIntent().getStringExtra("uname");
		tempra.setText("Temprature:" +temprature);
		 press.setText("Pressure  :" +pressure);
		sendd.setOnClickListener(new OnClickListener(){

			@SuppressWarnings("deprecation")
			@Override
			public void onClick(View arg0) {
				// TODO Auto-generated method stub
				String phone=mobile.getText().toString();
				SmsManager sms=SmsManager.getDefault();
				sms.sendTextMessage(phone, null, "temprature: "+temprature +"and"+"pressure: "+ pressure, null, null);
				Toast.makeText(getApplicationContext(), "Sms sent successfully", Toast.LENGTH_LONG).show();
				SendToServer senddata = new SendToServer();
				senddata.execute();
					
			}
			
		});
	}
	
	private class SendToServer extends AsyncTask<Void, String, Void> {
		/*String username=user.getText().toString();
		String password=pass.getText().toString();*/
		String res="";
		
		@Override
		  protected void onPreExecute() {
			  pbar.setVisibility(View.VISIBLE);
		  }

		  @Override
		  protected Void doInBackground(Void... unused) {
			  res = CallService.sendPHR(username, temprature, pressure, "monitorphr");
			  return null;
		  }

		  @Override    
		  protected void onProgressUpdate(String... data) {
					   
		  }

		  @Override
		  protected void onPostExecute(Void unused) {
			  AlertDialog.Builder dia=new AlertDialog.Builder(Sendactivity.this);
				dia.setTitle("Trust Agent");
				dia.setMessage(res);	
				dia.setCancelable(false);	
				dia.setPositiveButton("OK", new DialogInterface.OnClickListener(){
					@Override
					public void onClick(DialogInterface dialog, int which) {					
						Intent intent=new Intent(getBaseContext(),MainActivity.class);
						startActivity(intent);
						dialog.cancel();
						
					}				
				});			
				AlertDialog dialo=dia.create();
				dialo.show();
			  pbar.setVisibility(View.INVISIBLE);
		  
		  }
		}
	

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.sendactivity, menu);
		return true;
	}

}
