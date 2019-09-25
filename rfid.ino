
#include<SoftwareSerial.h>
SoftwareSerial  myserial(9,10);
int count=0;
char input[12];
boolean falg=0;
char id[12]={'5','3','0','0','2','9','1','3','C','4','A','D'};
void setup() {
  Serial.begin(9600);
  myserial.begin(9600);
}

void loop() {
  int flag;
  if(myserial.available())
  {
    count=0;
    while(myserial.available()&&count<12)
   
    {
      input[count]=myserial.read();
      count++;
      delay(5);
    }
    
    Serial.println(input); 
    
 for(int i=0;i<12;i++)
 {
  if(input[i]==id[i])
  {
    flag=0;
  }
  else
  {
     flag=1;
    break;
  }
 }
 if(flag==0)
 {
  Serial.println("valid id");
 }
 else
 {
   Serial.println("id error");
 }
  }

 
}
