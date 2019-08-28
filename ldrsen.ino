int ledpin=12;
int input=1;
void setup() {
  // put your setup code here, to run once:
  pinMode(1,INPUT);
  pinMode(12,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value=analogRead(input);
  delay(500);
  Serial.println(value);
 if(value<50)
    digitalWrite(ledpin,HIGH);
 else
    digitalWrite(ledpin,LOW);
    
  
}
