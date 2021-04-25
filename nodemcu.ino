#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266HTTPClient.h>
 
const char *ssid = "dann";  
const char *password = "danu12345";
 
//Web/Server address to read/write from 
const char *host = "http://192.168.43.60:8000/api/v1/data";   //your IP/web server address

int id_user = 1;
int id_car= 2;
int btn_empty=0;
int btn_filled= 0;
int btn_loading= 0;
int btn_trash= 0;
double latitude= -7.381100;
double longitude= 109.92456;
int xgyro= 12;
int ygyro= 12;
int speeds= 40;
int temp= 0;
int cycle= 1;
  

void setup() {
  delay(1000);
  Serial.begin(115200);
  
  WiFi.begin(ssid, password);     //Connect to your WiFi router
  Serial.println("");
 
  Serial.print("Connecting");
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  //If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP


}
 
void loop() {
 send();
 delay(5000);
}

void send(){
  
//    if(WiFi.status()== WL_CONNECTED){
      HTTPClient http;
      
      // Your Domain name with URL path or IP address with path
      http.begin(host);

      // Specify content-type header
      http.addHeader("Content-Type", "application/x-www-form-urlencoded");

       String postData = 
        "id_user=" + String(id_user)
        + "&id_car=" + String(id_car) 
        + "&btn_empty=" +String(btn_empty)
        + "&btn_filled=" +String(btn_filled)
        + "&btn_loading=" +String(btn_loading)
        + "&btn_trash=" +String(btn_trash)
        + "&latitude=" +String(latitude)
        + "&longitude=" +String(longitude)
        + "&xgyro=" +String(xgyro)
        + "&ygyro=" +String(ygyro)
        + "&speed=" +String(speeds)
        + "&temp=" +String(temp)
        + "&cycle=" +String(cycle);         
      int httpResponseCode = http.POST(postData);
      
       String payload = http.getString();//
 
      Serial.println(httpResponseCode);////
      Serial.println(payload);//
//      Serial.print("HTTP Response code: ");
//      Serial.println(httpResponseCode);
        
      // Free resources
      http.end();
//    }
//    else {
//      Serial.println("WiFi Disconnected");
//    }
  
}
