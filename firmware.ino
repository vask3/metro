#include <Adafruit_NeoPixel.h>

#define LED_PIN 2
#define NUM_LEDS 13

Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.setBrightness(40);
  strip.clear();
  strip.show();
}

void loop() {
  for (int i = 0; i < NUM_LEDS; i++) {
    strip.setPixelColor(i, strip.Color(0, 120, 255));
    strip.show();
    delay(120);
  }

  delay(400);

  for (int i = 0; i < NUM_LEDS; i++) {
    strip.setPixelColor(i, 0);
    strip.show();
    delay(80);
  }

  delay(500);
}