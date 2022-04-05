/* How to use the DHT-22 sensor with Arduino uno
   Temperature and humidity sensor
   More info: http://www.ardumotive.com/how-to-use-dht-22-sensor-en.html
   Dev: Michalis Vasilakis // Date: 1/7/2015 // www.ardumotive.com 
*/

//Libraries
#include <DHT.h>
#include <Wire.h> 
//#include <lcd.h>

//Constants
#define DHTPIN 20 // what pin the DHT22 Data is connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino


//Variables
int chk;
float hum;  //Stores humidity value
float temp; //Stores temperature value
float tempF;
void setup()
{
  Serial.begin(9600);
  dht.begin();
}

void loop()
{
  
  delay(2000);
  //Read data and store it to variables hum and temp
  hum = dht.readHumidity();
  temp = dht.readTemperature();
  tempF = ((temp * 1.8) + 32);
  //Print temp and humidity values to serial monitor
  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print(" %, Temp: ");
  Serial.print(temp);
  Serial.println(" Celsius");
  Serial.println(tempF);
  //Print temp and humidity values to LCD
  delay(2000); //Delay 2 sec between temperature/humidity check


}
