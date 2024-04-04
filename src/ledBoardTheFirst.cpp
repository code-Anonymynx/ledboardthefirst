#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Streaming.h>

#define gridPin D6
#define numLEDs 40

#define width 8
#define height 5

Adafruit_NeoMatrix grid(width, height, gridPin,
                        NEO_MATRIX_TOP + NEO_MATRIX_LEFT +
                            NEO_MATRIX_ROWS + NEO_MATRIX_PROGRESSIVE,
                        NEO_GRB + NEO_KHZ800);

void setup(void) {
  Serial.begin(115200);

  pinMode(LED_BUILTIN, OUTPUT);

  grid.begin();
  grid.setRotation(3);  // 3 for snake & text 0 for everything else
  grid.show();
  grid.setBrightness(255);
  grid.setTextWrap(false);

  Serial << "| LED Board The First |" << endl;
}

void loop(void) {
  grid.fillScreen(grid.Color(48, 213, 200));  // Fill the screen with a nice turquoise
  digitalWrite(LED_BUILTIN, HIGH);            // Turn on the onboard LED
  delay(500);                                 // wait 500ms

  grid.fillScreen(grid.Color(0, 0, 0));  // Fill the screen with black
  digitalWrite(LED_BUILTIN, LOW);        // Turn off the onboard LED
  delay(500);                            // wait 500ms
}
