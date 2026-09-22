int value=0;
float voltage ;
float R1= 30000.0;
float R2= 7500.0;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
value = analogRead(A0);
voltage= value*(5.0/1024)*((R1+R2)/R2);
//Serial.print("Voltage=");
Serial.println(voltage);
//Serial.println("V");
delay(1000);


  // put your main code here, to run repeatedly:

}
