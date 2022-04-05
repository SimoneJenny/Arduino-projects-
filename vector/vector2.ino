/*
  MsTimer2 is a small and very easy to use library to interface Timer2 with
  humans. It's called MsTimer2 because it "hardcodes" a resolution of 1
  millisecond on timer2
  For Details see: http://www.arduino.cc/playground/Main/MsTimer2
*/
#include <MsTimer2.h>
//vælg serial plotter
int EKG[] = {61, 61,61,61, 62,64, 68,67, 65 ,67, 64,61, 61,61,50, 120, 220, 100, 40, 61,61,61,61,61,64, 67, 70, 72, 74,74,73,70, 69, 63, 61, 61, 61, 61, 61};

// Switch on LED on and off each half second

void vektor()
{
  static int vectorVar =0;
  Serial.println(EKG[vectorVar ++]);
  int maxSize = sizeof(EKG)/sizeof(int);

  if(vectorVar >= maxSize)//test for end of EKG array 
  {
    vectorVar =0;
  }
  
}


void setup()
{
  MsTimer2::set(40, vektor); // 50ms sample period
  MsTimer2::start();
  Serial.begin(115200);
}

void loop()
{
}
