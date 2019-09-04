int code,calibration_time=30,ledpin=13,i,pirpin=3,takelowtime;
long unsigned int lowln,pause=5000;
boolean locklow=true;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pirpin,INPUT);
  pinMode(ledpin,OUTPUT);
  digitalWrite(pirpin,low);
  Serial.print(" callibrating sensor");
  for (i=0;i<calibration_time;i++){
    Serial.print(",");
    delay(1000);
  }
  Serial.print("done");
  Serial.print("sensor active");
  delay(50);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(pirpin)==HIGH){
    digitalWrite(ledpin,HIGH);
    if(locklow){
      locklow=false;
      Serial.println("--------");
      Serial.println("motion detected");
      Serial.println("millis()/100");
      Serial.println("sec");
      dealy(50);
    }
    takelowtime=true;
  }
  if(digitalread(pirpin)==low)
{
  digitalwrite(ledpin,LOW);
  if(takelowtime)
  {
    lowln=millis();
    takelowtime=false;
    Low phase
  }
  if(!locklow && millis()-lowln>pause)
  {
    locklow=true;
    Serial.print("motion ended at");
    Serial.print((millis()-pause)(1000));
    Serial.println("sec");
    delay(50);
    
    
  }
}
  
}
