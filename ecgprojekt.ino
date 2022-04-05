#include <MsTimer2.h>

int EKG[] = {61, 61, 61, 61, 62, 64, 68, 67, 67, 65, 64, 61, 61, 61, 50, 120, 220, 100, 40, 61, 61, 61, 61, 61, 64, 67, 70, 72, 74, 74, 73, 70, 69, 63, 61, 61, 61, 61, 61};
int BPM = 0;
int pin = 7;
int volumen = analogRead(A0);
static int oldVolumen = 0;
int TimeInterval = 0;
static int newTime = 0;
static uint8_t index = 0;
static int oldTime = 0;

void vector() {
  static int vectorVar = 0;
  static int timeSetting = 0;
  //Serial.println(EKG[vectorVar++]);
  int maxSize = sizeof(EKG) / sizeof(int);
  volumen = map(analogRead(A0), 0, 1023, 0, 100);
  int nyEKG = 0;
  if (abs(TimeInterval - newTime) > 2) // lav et filter der fjerner quantizerings støj fra A/D konverter
  {
    newTime = TimeInterval;
  }
  
  if (abs(volumen - oldVolumen) > 2) // lav et filter der fjerner quantizerings støj fra A/D konverter
  {
    oldVolumen = volumen;
  }
  if (vectorVar >= maxSize) //Test for end of EKG array...
    vectorVar = 0;
  nyEKG = EKG[vectorVar++] * volumen / 100;

  if(nyEKG >= 200)
  tone(pin, 440, 10);

  if(nyEKG == 0)
  tone(pin, 440, 100);

  Serial.println(nyEKG);
  Serial.print(",");
  
  Serial.println(timeSetting);
   
  int tempVal = TimeIntervalTest();
  if(timeSetting != tempVal){
    timeSetting = tempVal;
    MsTimer2::set(tempVal, vector); // 500ms period
    MsTimer2::start();
  }
}

void setup()
{
  //  timeSetting = temTimeVal;
  MsTimer2::set(50, vector); // 500ms period
  MsTimer2::start();
  Serial.begin(115200);
}

void loop()
{

}
