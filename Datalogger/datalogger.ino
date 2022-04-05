#include <MsTimer2.h>

//åben seriel Plotter
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  MsTimer2::set(50, analogin); // 50ms period
  MsTimer2::start();

}

void loop() {
  // put your main code here, to run repeatedly:
  

}
//ISR rutine = ISR = interupt service routine
void analogin()
{
  Serial.println((float)map(analogRead(A0), 0, 1023, -10, 31)); //(float) = at caste
}
