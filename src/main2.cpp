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

// Colour palette 
 #define BlueL grid.Color(48, 213, 200)
 #define Blue grid.Color(0, 105, 92)
 #define BlueG grid.Color(50, 115, 53)
 #define BlueB grid.Color(157, 214, 220)
 #define BlueD grid.Color(32, 53, 56)
 #define BlueDD grid.Color(11, 18, 20)
 
 void setup(void) {
   Serial.begin(115200);

   grid.begin();
   grid.setRotation(3);  // 3 for snake & text 0 for everything else
   grid.show();
   grid.setBrightness(125);
   grid.setTextWrap(false);

   Serial << "| LED Board The First |" << endl;
 }

void loop(void) {
  // The snake moves from the bottom to the top, turning the LEDs on
    int pixelPositions[][3] = {
        {0, 0, 1}, {0, 1, 1}, {0, 2, 1}, {0, 3, 1}, {0, 4, 1},
        {0, 5, 1}, {0, 6, 1}, {0, 7, 1}, {1, 7, 1}, {1, 6, 1},
        {1, 5, 1}, {1, 4, 1}, {1, 3, 1}, {1, 2, 1}, {1, 1, 1},
        {1, 0, 1}, {2, 0, 1}, {2, 1, 1}, {2, 2, 1}, {2, 3, 1},
        {2, 4, 1}, {2, 5, 1}, {2, 6, 1}, {2, 7, 1}, {3, 7, 1},
        {3, 6, 1}, {3, 5, 1}, {3, 4, 1}, {3, 3, 1}, {3, 2, 1},
        {3, 1, 1}, {3, 0, 1}, {4, 0, 1}, {4, 1, 1}, {4, 2, 1},
        {4, 3, 1}, {4, 4, 1}, {4, 5, 1}, {4, 6, 1}, {4, 7, 1},
    };

    for (size_t i = 0; i < sizeof(pixelPositions) / sizeof(pixelPositions[0]); i++) {
        int x = pixelPositions[i][0];
        int y = pixelPositions[i][1];
        int color = pixelPositions[i][2];

        grid.drawPixel(x, y, color ? BlueDD : 0);
        grid.show();
        delay(30);
        grid.drawPixel(x, y, color ? BlueB : 0);
        grid.show();
        delay(50);
        grid.drawPixel(x, y, color ? BlueL : 0);
        grid.show();
        delay(75);
        grid.drawPixel(x, y, color ? Blue : 0);
        grid.show();
        delay(150);
        grid.drawPixel(x, y, color ? BlueD : 0);
        grid.show();
        delay(75);
    }
  // the snake moves from the top to the bottom, turning the LEDs off
    int pixelPositions2[][3] = {
        {4, 7, 1}, {4, 6, 1}, {4, 5, 1}, {4, 4, 1}, {4, 3, 1},
        {4, 2, 1}, {4, 1, 1}, {4, 0, 1}, {3, 0, 1}, {3, 1, 1},
        {3, 2, 1}, {3, 3, 1}, {3, 4, 1}, {3, 5, 1}, {3, 6, 1},
        {3, 7, 1}, {2, 7, 1}, {2, 6, 1}, {2, 5, 1}, {2, 4, 1},
        {2, 3, 1}, {2, 2, 1}, {2, 1, 1}, {2, 0, 1}, {1, 0, 1},
        {1, 1, 1}, {1, 2, 1}, {1, 3, 1}, {1, 4, 1}, {1, 5, 1},
        {1, 6, 1}, {1, 7, 1}, {0, 7, 1}, {0, 6, 1}, {0, 5, 1},
        {0, 4, 1}, {0, 3, 1}, {0, 2, 1}, {0, 1, 1}, {0, 0, 1},
    };  

    for (size_t i = 0; i < sizeof(pixelPositions2) / sizeof(pixelPositions2[0]); i++) {
        int x = pixelPositions2[i][0];
        int y = pixelPositions2[i][1];
        int color = pixelPositions2[i][2];

        grid.drawPixel(x, y, color ? BlueL : 0);
        grid.show();
        delay(75);
        grid.drawPixel(x, y, color ? Blue : 0);
        grid.show();
        delay(150);
        grid.drawPixel(x, y, color ? BlueD : 0);
        grid.show();
        delay(75);
        grid.drawPixel(x, y, color ? BlueDD : 0);
        grid.show();
        delay(50);
        grid.drawPixel(x, y, color ? 0 : 0);
        grid.show();
        delay(30);
    } 
}


