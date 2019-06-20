int potentiopin = 2;
int  potentiovalue = 0;
void setup() {
  // put your setup code here, to run once:   
pinMode(12,OUTPUT);
pinMode(2,INPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
potentiovalue = digitalRead(potentiovalue);
  if(potentiovalue == 0)
{
digitalWrite(12,LOW);
delay(100); 
digitalWrite(12,HIGH);
delay(100);
}
}
