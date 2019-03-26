package ru.driim.bluetoothterminal;

import java.io.IOException;

import org.ksoap2.SoapEnvelope;
import org.ksoap2.serialization.SoapObject;
import org.ksoap2.serialization.SoapPrimitive;
import org.ksoap2.serialization.SoapSerializationEnvelope;
import org.ksoap2.transport.HttpTransportSE;
import org.xmlpull.v1.XmlPullParserException;


public class CallService {
	
	private static String NAMESPACE="http://patient.com/";
	private static String URL="http://192.168.43.65:8080/PatientService/NewWebService?WSDL";
	private static String SOAP_ACTION="http://rsa.com/";
	private int Time_Out=3000;
	
	public static String loginService(String username,String password,String method) {
		String restex=null;
		SoapObject soap=new SoapObject(NAMESPACE, method);
		soap.addProperty("username",username);
		soap.addProperty("password",password);
		SoapSerializationEnvelope envelope=new SoapSerializationEnvelope(SoapEnvelope.VER11);
		envelope.setOutputSoapObject(soap);
		HttpTransportSE http=new HttpTransportSE(URL);
		try { 
			http.call(NAMESPACE+method, envelope);
			SoapPrimitive primitive =(SoapPrimitive) envelope.getResponse();
			restex=primitive.toString();
			
		} catch (IOException e) {
			e.printStackTrace();
			return "error";
			
		} catch (XmlPullParserException e) {
			e.printStackTrace();
			return "error";
			
		}
		
		return restex;
	}
	
	public static String registerService(String username,String password,String age,String emailid,String mobile,String location,String method) {
		String restex=null;
		SoapObject soap=new SoapObject(NAMESPACE, method);
		soap.addProperty("username",username);
		soap.addProperty("password",password);
		soap.addProperty("age",age);
		soap.addProperty("emailid",emailid);
		soap.addProperty("mobile",mobile);
		soap.addProperty("location",location);
		SoapSerializationEnvelope envelope=new SoapSerializationEnvelope(SoapEnvelope.VER11);
		envelope.setOutputSoapObject(soap);
		HttpTransportSE http=new HttpTransportSE(URL);
		try {
			http.call(NAMESPACE+method, envelope);
			SoapPrimitive primitive =(SoapPrimitive) envelope.getResponse();
			restex=primitive.toString();
			
		} catch (IOException e) {
			e.printStackTrace();
			return "error";
			
		} catch (XmlPullParserException e) {
			e.printStackTrace();
			return "error";
			
		}
		
		return restex;
	}
	public static String sendPHR(String username,String pressure,String temperture,String methodName) {
		String restxt=null;
		SoapObject request =new SoapObject(NAMESPACE, methodName);
		request.addProperty("username",username);
		request.addProperty("temperature",temperture);
		request.addProperty("pressure",pressure);
		SoapSerializationEnvelope envelope=new SoapSerializationEnvelope(SoapSerializationEnvelope.VER11);
		envelope.setOutputSoapObject(request);
		HttpTransportSE http=new HttpTransportSE(URL);
		try {
			http.call(SOAP_ACTION+methodName,envelope);
			SoapPrimitive primitive=(SoapPrimitive) envelope.getResponse();
			restxt=primitive.toString();
			return restxt;			
		}
		catch(Exception e){
			return "error occured";			
		}		
	}

}
