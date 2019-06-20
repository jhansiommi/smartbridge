int ldr;
void setup()
{
pinMode(33,INPUT); 
Serial.begin(115200);
}
void loop()
{
  ldr = analogRead(33);
  Serial.print("ldr value:");
  Serial.println(ldr);
  
 delay(200);
}
