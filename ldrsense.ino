#include<Servo.h>
Servo S;
int led1=13;
int pinsense=1,pirsense=12;
void setup() {
  // put your setup code here, to run once:
  pinMode(pirsense,INPUT);
  pinMode(led1,OUTPUT);
  S.attach(5);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value=analogRead(pinsense);
  int value1=digitalRead(pirsense);
  Serial.println(value1);
  Serial.println(value);
  if(value1==HIGH)
  {
    if(value<100)
    {
          digitalWrite(led1,HIGH);
          Serial.println("Led ON");
    }
     for(int i=0;i<=180;i++)
     {
        S.write(i); 
        //Serial.println("Servo");   
     }
     for(int i=180;i>0;i--)
     {
        S.write(i); 
        //Serial.println("Servo");   
     }
     Serial.println("Human Presence");
    
  }
  else
      
    {  digitalWrite(led1,LOW);
      Serial.println("NO Human");
    }
    delay(1000);
  }
  
  
