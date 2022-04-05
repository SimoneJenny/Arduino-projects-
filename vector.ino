/*
  MsTimer2 is a small and very easy to use library to interface Timer2 with
  humans. It's called MsTimer2 because it "hardcodes" a resolution of 1
  millisecond on timer2
  For Details see: http://www.arduino.cc/playground/Main/MsTimer2
*/
#include <MsTimer2.h>
//vælg serial plotter

// Switch on LED on and off each half second

void vektor()
{
  ///generer en vektor der rotere rundt i 0 og 359 grader (pga. 0)
  static int vectorVar =0;
  vectorVar 
  ++; //tæller op
  if(vectorVar == 360)
  {
    vectorVar =0;
  }

  float sinVar = 0.0;
  float cosVar = 0.0;
  float kurve3 = 0.0;
  int volume = analogRead(A0); // til ar gøre vores styrepind resultat pænere  
  static int oldVolume =0;
  if(abs(volume - oldVolume)>2) // laver et filter der fjerner quantixering støj fra A/D konverter
  {
    oldVolume = volume;
  }
  
  sinVar = sin((float)vectorVar*PI/180.0);
  cosVar = cos((float)vectorVar*PI/180.0);
  kurve3 = sinVar * cosVar *map(oldVolume, 0, 1023, 0, 10); //Styrepind
  //Serial.println(sin((float)vectorVar*PI/180.0));

  Serial.print(oldVolume);

  Serial.print(sinVar);
  Serial.print(",");
  Serial.print(cosVar);
  Serial.print(",");
  Serial.print(kurve3);
  Serial.println(); //terminate line
}

void setup()
{
  

  MsTimer2::set(5, vektor); // 50ms sample period
  MsTimer2::start();
  Serial.begin(115200);
}

void loop()
{
}
