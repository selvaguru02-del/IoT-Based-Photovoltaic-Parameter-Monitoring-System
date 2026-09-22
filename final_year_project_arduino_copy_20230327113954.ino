
int value=0;
float voltage ;
float R1= 30000.0;
float R2= 7500.0;
float power = 1.0;

double calcLightIntensity(int AnVal, int Resistor){

  double Vout= AnVal*0.0048828125;
  int lux=((2500/Vout-500)/Resistor);
  return lux;
  }
#include "dht.h"
#define dht_apin A3 // Analog Pin sensor is connected to
 
dht DHT;
void setup() {
  Serial.begin(9600); // put your setup code here, to run once:

}

void loop() {
value = analogRead(A0);
voltage= value*(5.0/1024)*((R1+R2)/R2);
Serial.print("Voltage=");
Serial.print(voltage);
Serial.println("V");
delay(1000);

int adc = analogRead(A1);
  float sensor = adc*5.0/1024.0;
  float current = (sensor-2.50)/0.185;
   if (current < 0.16){
    current = 0;
  }
   Serial.print ("Current=");
  Serial.print(current);
  Serial.println("A");
  delay(1000);
  // put your main code here, to run repeatedly:
 power = voltage*current;
 Serial.print("Power=");
 Serial.print(power);
 Serial.println("W");
 delay(1000);
 
  int analogVal = analogRead(A2); 
   int Resistance= 10; 

   Serial.print("Light Intensity:");
   Serial.print(int(calcLightIntensity(analogVal, Resistance )));
   Serial.println(" lux");
   delay(1000);

  DHT.read11(dht_apin);
    
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.println("%  ");
    delay(1000);
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C ");  
    delay(1000);
 }
