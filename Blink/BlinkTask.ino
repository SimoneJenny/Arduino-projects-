#include <Arduino_FreeRTOS.h> //Henter bibliotek 

int pause1 = 2700;
int pause2 = 1300; 
bool ledig = true;

// Bruger primtal i pauser, så de aldrig rammer hinanden.
// define two tasks for Blink & Blink
//void TaskBlink01( void *pvParameters );
//void TaskBlink02( void *pvParameters );

// the setup function runs once when you press reset or power the board
void setup() {
  
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB, on LEONARDO, MICRO, YUN, and other 32u4 based boards.
  }

  // Now set up two tasks to run independently.
  //indbygget funktion
  xTaskCreate(
    TaskBlink01
    ,  "Blink01"   // A name just for humans
    ,  128  // This stack size can be checked & adjusted by reading the Stack Highwater
    ,  NULL
    ,  2  // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
    ,  NULL );

  xTaskCreate(
    TaskBlink02
    ,  "Blink02"   // A name just for humans
    ,  128  // This stack size can be checked & adjusted by reading the Stack Highwater
    ,  NULL
    ,  3  // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
    ,  NULL );

  // Now the task scheduler, which takes over control of scheduling individual tasks, is automatically started.
}

void loop()
{
  // Empty. Things are done in Tasks.
}

/*---------------------- Tasks ---------------------*/

//Blink 1 created and activated 
void TaskBlink01(void *pvParameters)  // This is a task.
{
  (void) pvParameters;
  ledig = true;
  Serial.println("Blink 1 er ledig");

  if(ledig)
  {
    ledig = false;
    // initialize digital LED_BUILTIN on pin 13 as an output.
    pinMode(LED_BUILTIN, OUTPUT);

  for (;;) // A Task shall never return or exit.
  {
    Serial.println("Blink 1 on - ikke ledig");
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    vTaskDelay( pause1 / portTICK_PERIOD_MS ); // wait for one second
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    vTaskDelay( pause1 / portTICK_PERIOD_MS ); // wait for one second
  }
   //ledig = true;
  //Serial.println("Blink 1 er ledig");
  } 
  
}

//Blink 2 created and activated 
void TaskBlink02(void *pvParameters)  // This is a task.
{
  (void) pvParameters;
   ledig = true;
  Serial.println("Blink 2 er ledig");
 if(ledig)
 {
  ledig = false;
   // initialize digital LED_BUILTIN on pin 13 as an output.
   pinMode(LED_BUILTIN, OUTPUT);

  for (;;) // A Task shall never return or exit.
  {
    Serial.println("Blink 2 on - ikke ledig");
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    vTaskDelay( pause2 / portTICK_PERIOD_MS ); // wait for one second
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    vTaskDelay( pause2 / portTICK_PERIOD_MS ); // wait for one second   
  }
 //ledig = true;
 //Serial.println("Blink 2 er ledig");
}

 
 }

  
