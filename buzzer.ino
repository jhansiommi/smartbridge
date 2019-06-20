int buzzer = 2;
int  buzzervalue = 0;
void setup()
{
 pinMode(2,OUTPUT);
void loop()
{
digitalWrite(2,LOW);
delay(100);
digitalWrite(2,HIGH);
delay(100);
}
}
