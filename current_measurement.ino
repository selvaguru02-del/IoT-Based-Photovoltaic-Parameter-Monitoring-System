void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  int adc = analogRead(A1);
  float sensor = adc*5.0/1023.0;
  float current = (sensor-2.45)/0.185;
   
  if (current < 0.16){
    current = 0;
  }
  Serial.print ("Current=");
  Serial.print(current);
  Serial.println("A");
  delay(1000);
  // put your main code here, to run repeatedly:

}
