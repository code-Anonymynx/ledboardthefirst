#include <Adafruit_NeoPixel.h>

#define PIN           D4    // Pin connected to the NeoPixels
#define NUM_PIXELS    40    // Number of NeoPixels

Adafruit_NeoPixel pixels(NUM_PIXELS, PIN, NEO_GRB + NEO_KHZ800);

// Function prototype
void colorWipe(uint32_t color, int wait);

void setup() {
  pixels.begin();  // Initialize NeoPixel strip
  pixels.clear();  // Clear any existing pixels
  pixels.show();   // Make sure to update the strip to reflect changes
}

void loop() {
  // Here you can write code to control the LEDs
  // For example, to light up all LEDs in red:
  colorWipe(pixels.Color(255, 0, 0), 50);  // Red color, 50 ms delay per pixel
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<NUM_PIXELS; i++) {
    pixels.setPixelColor(i, color);
    pixels.show();
    delay(wait);
  }
}