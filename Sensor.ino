#include <math.h>
int pinturbidity = A0;
int pinPh   = A1;  //This is where our Output data goes
float lsi=0;
float Ca;
float cya;
float tds;
float alkalinity;
float ph_calculated;
float A,B,C,D;
void setup() 
{
  Serial.begin(9600);
         
}
void loop() 
{
  int turbidity = analogRead(pinturbidity);//Read the analog pin for temp
  float voltage_turbidity = turbidity * (5.0 / 1024.0);
   float ph_measured = analogRead(pinPh);    // Read ph value   
   float pHVol=(float)ph_measured*5.0/1024/6;
   float phValue = -5.70 * pHVol + 21.34; 
//  temp = temp * 0.48828125;   // convert output (mv) to readable celcius
  //Serial.println("Turbidity: ");
  //Serial.print(voltage_turbidity);
 // Serial.println("C");  //print the temperature status
  //Serial.println("Ph value=");
  //Serial.print(phValue);

  Serial.print(phValue);
  Serial.print(",");
  Serial.print(voltage_turbidity);
  Serial.println();
  delay(1000);

//   A=(log(tds)-1)/10;
//   B= ((-13.12) * log(temp + 273)) + 34.55 ;
//   C= log(Ca) - 0.4;
//   D=log(alkalinity);
//   
//   ph_calculated=(9.3+A+B)-(C+D);
//   lsi=(ph_measured)-(ph_calculated);
//   Serial.println(lsi);
//
//   if(lsi>0)
//   {
//     Serial.println("xyz"); 
//   }
//   else if(lsi=0)
//   {
//    Serial.println("ccc");
//   }
//   else
//   {
//    Serial.println("zzz");
//   }
//
//   delay(1000);
//
//    
//   
}
