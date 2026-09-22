void setup() {
 Serial.begin(9600); // put your setup code here, to run once:

}

void loop() {
 char buffer [20]="";
 if (Serial.available()>0){
   Serial.readBytesUntil('\n',buffer,20);
   Serial.println(buffer);
 } // put your main code here, to run repeatedly:

}
