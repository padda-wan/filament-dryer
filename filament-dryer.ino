// Adafruit DHT11 lib sucks, use this instead
// https://drive.google.com/uc?export=download&id=1eG0a4lXQ2tNuTy_O9OWXuHO-EYbmHRDT

#include <dht11.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET     -1 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int DHT11_pin=2;
dht11 DHT11_sensor;

void setup()
{
  Serial.begin(115200);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); 
  }
  display.display();
  display.clearDisplay();
}

void loop()
{
  int chk = DHT11_sensor.read(DHT11_pin);
  drawDisplay();
  delay(500);
}

void drawDisplay(){

  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println(F("Hello, world!"));

  display.setTextColor(BLACK, WHITE); // Draw 'inverse' text
  display.println(3.141592);

  display.setTextSize(2);
  display.setTextColor(WHITE);

  // Temperature reading
  display.print(F("TEMP:"));
  display.print(DHT11_sensor.temperature);
  display.write(9);

  display.println();

  // Humidity reading
  display.print(F("HUM:"));
  display.print(DHT11_sensor.humidity);
  display.print(F("%"));

  display.display();
  delay(2000);

}