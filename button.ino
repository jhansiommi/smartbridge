int buttonpin = 12;
int  buttonState =0;
void setup() {
  // put your setup code here, to run once:
pinMode(2,OUTPUT);
pinMode(12,INPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
buttonState = digitalRead(buttonpin);
  if(buttonState ==0)
{
digitalWrite(2,LOW);
delay(100);
digitalWrite(2,HIGH);
delay(100);
}
}
