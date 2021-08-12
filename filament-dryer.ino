// Adafruit DHT11 lib sucks, use this instead
// https://drive.google.com/uc?export=download&id=1eG0a4lXQ2tNuTy_O9OWXuHO-EYbmHRDT

#include <dht11.h>
#include <math.h>

int DHT11_pin=2;
dht11 DHT11_sensor;
float max_temp=0.0;
float current_temp=0.0;

void setup()
{
  Serial.begin(9600);
  max_temp = (float)DHT11_sensor.temperature;
}

void loop()
{
  int chk = DHT11_sensor.read(DHT11_pin);

  current_temp = (float)DHT11_sensor.temperature;
  if (current_temp > max_temp){
      max_temp = current_temp;
  }

  Serial.print("Humidity (%): ");
  Serial.print((float)DHT11_sensor.humidity, 2);
  Serial.print(" ");

  Serial.print("Temp (Celcius): ");
  Serial.print((float)DHT11_sensor.temperature);
  Serial.print(" ");

  Serial.print("Dew Point: ");
  Serial.print(DHT11_sensor.dewPoint(), 2);
  Serial.print(" ");

  Serial.print("Max Temp: ");
  Serial.print(max_temp);
  Serial.print(" ");

  Serial.println();
  Serial.println("");
  delay(500);

}