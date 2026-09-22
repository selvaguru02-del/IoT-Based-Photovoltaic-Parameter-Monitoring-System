#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <SoftwareSerial.h>

// Set these to run example.
#define FIREBASE_HOST "one1-3ae11-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "ejKyp1XJLxSqBXzXfyh1yQ3j2rCkxGmJhihnrBwt"
#define WIFI_SSID "FTTH-1B79"
#define WIFI_PASSWORD "12345678"


void setup() {
  Serial.begin(9600);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  
}
void loop() {
  char buffer [60]="";
 if (Serial.available()>0){
   Serial.readBytesUntil('\n',buffer,60);
   Serial.println(buffer);
  String fire = String(buffer);

  // set string value
   Firebase.setString("PV PARAMETERS ",fire);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /message failed:");
      Serial.println(Firebase.error());  
      return;
  }
 
 } 
 
}
