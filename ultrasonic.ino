#include<LiquidCrystal.h>
const int trigpin=3,echopin=2;
int buzzer=1;

LiquidCrystal lcd(8,9,4,5,6,7);

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
   
   lcd.begin(16,2);
   pinMode(buzzer,OUTPUT);   
   lcd.setCursor(8,8);
}

void loop() {
  // put your main code here, to run repeatedly:
   long duration,inches,cm;
   lcd.setCursor(0,1);
   pinMode(trigpin,OUTPUT);
   digitalWrite(trigpin,LOW);
   delay(2);
   digitalWrite(trigpin,HIGH);
   delay(10);
   digitalWrite(trigpin,LOW);
   pinMode(echopin,INPUT);
   duration=pulseIn(echopin,HIGH);
   inches=microsecondsToInches(duration); 
   cm=microsecondsToCentimeters(duration);
   lcd.print(inches);
   lcd.print(" in and ");
   lcd.print(cm);
   lcd.print(" cm");
   if(inches<10)
   {
    Serial.println("if");
   digitalWrite(buzzer,HIGH);
   }
   else
   {
    Serial.println("else");
    digitalWrite(buzzer,LOW);
   }
   
   Serial.println(inches);
   Serial.println(cm);
   
   delay(1000);
}

long microsecondsToInches(long m){
  return m/74/2;
}

long microsecondsToCentimeters(long c){
  return c*0.034/2;
}
