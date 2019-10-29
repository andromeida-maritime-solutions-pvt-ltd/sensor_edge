#include <math.h>
int pinTemp = A0;
int pinPh   = A1;  //This is where our Output data goes
float lsi=0;
float Ca;
float cya;
float tds;
float alkalinity;
float ph_calculated;
float A,B,C,D;
void setup() {
  Serial.begin(9600);     
}
void loop() {
  int temp = analogRead(pinTemp);  //Read the analog pin for temp
  float ph_measured = analogRead(pinPh);      // Read ph value    
  temp = temp * 0.48828125;   // convert output (mv) to readable celcius
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println("C");  //print the temperature status
  Serial.print(ph_measured);
  delay(1000);

   A=(log(tds)-1)/10;
   B= ((-13.12) * log(temp + 273)) + 34.55 ;
   C= log(Ca) - 0.4;
   D=log(alkalinity);
   
   ph_calculated=(9.3+A+B)-(C+D);
   lsi=(ph_measured)-(ph_calculated);
   Serial.println(lsi);

   if(lsi>0)
   {
     Serial.println("xyz"); 
   }
   else if(lsi=0)
   {
    Serial.println("ccc");
   }
   else
   {
    Serial.println("zzz");
   }

   delay(1000);

    
   
}
