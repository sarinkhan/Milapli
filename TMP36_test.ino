int tempPin=A0;

float readTemp(int pin)
{
  float bv=analogRead(pin);
  float mv=bv*5/1024.0;
  float temperatureC = (mv - 0.5) * 100 ;
  return temperatureC;
}

float readAvgTemp(int pin, int waitDelay, int count)
{
   int k=0;
   float sum=0.0;
   for(k=0;k<count;k++)
   {
       sum=sum + readTemp(pin);
       delay(waitDelay);
   }
   float avg=sum/(float)count;
   return avg;
}

void setup()
{
    Serial.begin(9600);
}

void loop()
{
  Serial.print("Temperature : ");
  Serial.println(readTemp(tempPin));
  delay(100);
}

