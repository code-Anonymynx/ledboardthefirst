/**
 * Blink
 *
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */
#include <Arduino.h>
#include <FastLED.h>

#define NUM_LEDS 40 
CRGB leds[NUM_LEDS];

// put function declarations here:
//int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<NEOPIXEL, 6>(leds, NUM_LEDS);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  leds[0] = CRGB::White; FastLED.show(); delay(30);
  leds[0] = CRGB::Black; FastLED.show(); delay(30);
  
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_BUILTIN, HIGH);
  // wait for a second
  delay(1000);
  // turn the LED off by making the voltage low
  digitalWrite(LED_BUILTIN, LOW);
  // wait for a second
  delay(1000);
}

