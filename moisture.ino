#include<Servo.h>
Servo s;

int input=0,auoutput=9;
void setup() {
  // put your setup code here, to run once:
  
  pinMode(0,INPUT);
  pinMode(auoutput,OUTPUT);
  s.attach(9);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value=analogRead(input);
  delay(500);
  Serial.println(value);
 if(value>450){
    
    for(int i=0;i<180;i++)
    {
      s.write(i);
      delay(30);
    }
    for(int i=180;i>=0;i--)
    {
      s.write(i);
      delay(30);
      
    }}
    else 
    s.write(0);
    

    
  
  
}
