#include "Adafruit_NeoPixel.h"
#define PIXEL_COUNT 20
#define PIXEL_PIN    5

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);
#include "Ultrasonic.h"

Ultrasonic ultrasonic(0);

void setup() {
  strip.setBrightness(255);
  strip.begin();
  strip.show();
  Serial.begin(9600);
}
int i = 0;
void loop() {

  int RangeInCentimeters = ultrasonic.MeasureInCentimeters();
  int value = map(RangeInCentimeters, 1, 50, 20, 0);

  Serial.print("value corrisponde a ");
  Serial.print(value);

  int j = 20 - value;
  Serial.print(" j corrisponde a ");
  Serial.print(j);

  int x = 20 - j;
  Serial.print(" x corrisponde a ");
  Serial.println(x);

  for (i = 0; i < value; i++)
  {
    strip.setPixelColor(i, strip.Color(0, 150, 0));
    strip.show();
  }
  for (x = 20 - j; x < 20; x++)
  {
    strip.setPixelColor(x, strip.Color(150, 0, 0));
    strip.show();
  }
  delay(25);

}
