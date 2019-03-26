/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.patient;

import com.commondb.Common_DB;
import java.sql.ResultSet;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.jws.WebService;
import javax.jws.WebMethod;
import javax.jws.WebParam;

/**
 *
 * @author Java
 */
@WebService(serviceName = "NewWebService")
public class NewWebService {

    /**
     * This is a sample web service operation
     */
    @WebMethod(operationName = "Login")
    public String Login(@WebParam(name = "username") String username, @WebParam(name = "password") String password) {
         try {
           Common_DB cd=new Common_DB();
            ResultSet rs=Common_DB.LoginCheck("psjav26", "spoc","username","password", username, password);
            if(rs.next()) {
            return "success";
            }
            else {
                return "username or password is invalid";
            }
        } catch (Exception ex) {
            Logger.getLogger(NewWebService.class.getName()).log(Level.SEVERE, null, ex);
            return "server temporarily not available";
        }       
    } 
    
     @WebMethod(operationName = "Register")
    public String Register(@WebParam(name = "username") String username,@WebParam(name = "password") String password,@WebParam(name = "age") String age,@WebParam(name = "emailid") String emailid,@WebParam(name = "mobile") String mobile, @WebParam(name = "location") String location) {
       try {
           Common_DB cd=new Common_DB();
            int rs=Common_DB.InsertTable("psjav26", "INSERT INTO register(username,password,age,emailid,mobile,location) VALUES('"+username+"','"+password+"','"+age+"','"+emailid+"','"+mobile+"','"+location+"')");
            
            int r=Common_DB.InsertTable("psjav26", "INSERT INTO spoc(username,password) VALUES('"+username+"','"+password+"')");
            if((rs>0) && (r>0)) {
            return "success";
            }
            else {
                return "username is already exists";
            }
        } catch (Exception ex) {
            Logger.getLogger(NewWebService.class.getName()).log(Level.SEVERE, null, ex);
            return "server temporarily not available";
        }
        
    }
    @WebMethod(operationName = "monitorphr")
    public String monitorphr(@WebParam(name = "username") String username,@WebParam(name = "temperature") String temperature, @WebParam(name = "pressure") String pressure) {
        try {
            
            //String PassWord=DC.Enc(password,username);
            // int i1 = Common_DB.InsertTable("psjav26", "INSERT INTO spoc(username,password,pressure,temperature) VALUES ('"+username+"','"+PassWord+"','"+pressure+"','"+temperature+"')");
              int i = Common_DB.InsertTable("psjav26", "UPDATE spoc SET pressure='"+pressure+"',temperature='"+temperature+"' WHERE username='"+username+"'");
              System.out.println(i);  
              if(i>0) {
                return "phr updated successfully";
              }
              else
              {
                   return "failed to update phr";
              }
    
        } catch (Exception ex) {
            Logger.getLogger(NewWebService.class.getName()).log(Level.SEVERE, null, ex);
            return "failed to update phr";
        }
        
    }
}
