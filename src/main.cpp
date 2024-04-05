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
 #define Blue grid.Color(0, 105, 92)
 #define BlueG grid.Color(50, 115, 53)

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
   grid.fillScreen(grid.Color(48, 213, 200));  
   grid.show();           
   delay(800);                                 

   grid.fillScreen(grid.Color(0, 105, 92));  
   grid.show();        
   delay(800); 

   grid.fillScreen(grid.Color(50, 115, 53));  
   grid.show();         
   delay(800); 

   grid.fillScreen(grid.Color(0, 0, 0));  
   grid.show();       
   delay(20);   
   
   // Iteration 1 - 11 turn Blue
   grid.drawPixel(4,0, Blue);
   grid.drawPixel(4,3, Blue);
   grid.drawPixel(4,6, Blue);
   grid.drawPixel(3,5, Blue);
   grid.drawPixel(2,1, Blue);
   grid.drawPixel(2,4, Blue);
   grid.drawPixel(2,7, Blue);
   grid.drawPixel(1,0, Blue);
   grid.drawPixel(1,6, Blue);
   grid.drawPixel(0,2, Blue);
   grid.drawPixel(0,4, Blue);
   grid.show();
   delay(800);

  // Iteration 2 - 14 turn Blue
   grid.drawPixel(4,1, Blue);
   grid.drawPixel(4,2, Blue);
   grid.drawPixel(4,7, Blue);
   grid.drawPixel(3,0, Blue);
   grid.drawPixel(3,3, Blue);
   grid.drawPixel(3,6, Blue);
   grid.drawPixel(2,2, Blue);
   grid.drawPixel(2,5, Blue);
   grid.drawPixel(1,1, Blue);
   grid.drawPixel(1,4, Blue);
   grid.drawPixel(1,7, Blue);
   grid.drawPixel(0,3, Blue);
   grid.drawPixel(0,5, Blue);
   grid.drawPixel(0,6, Blue);
   grid.show();
   delay(800);

  // Iteration 3 - 11 turn blueG, 7 turn blue
   grid.drawPixel(4,0, BlueG);
   grid.drawPixel(4,3, BlueG);
   grid.drawPixel(4,6, BlueG);
   grid.drawPixel(3,5, BlueG);
   grid.drawPixel(2,1, BlueG);
   grid.drawPixel(2,4, BlueG);
   grid.drawPixel(2,7, BlueG);
   grid.drawPixel(1,0, BlueG);
   grid.drawPixel(1,6, BlueG);
   grid.drawPixel(0,2, BlueG);
   grid.drawPixel(0,4, BlueG);
   grid.drawPixel(4,4, Blue);
   grid.drawPixel(3,2, Blue);
   grid.drawPixel(3,7, Blue);
   grid.drawPixel(2,0, Blue);
   grid.drawPixel(2,3, Blue);
   grid.drawPixel(1,5, Blue);
   grid.drawPixel(0,1, Blue);
   grid.show();
   delay(800);

   //  Iteration 4 - 14 turn blueG, 8 turn blue
   grid.drawPixel(4,1, BlueG);
   grid.drawPixel(4,2, BlueG);
   grid.drawPixel(4,7, BlueG);
   grid.drawPixel(3,0, BlueG);
   grid.drawPixel(3,3, BlueG);
   grid.drawPixel(3,6, BlueG);
   grid.drawPixel(2,2, BlueG);
   grid.drawPixel(2,5, BlueG);
   grid.drawPixel(1,1, BlueG);
   grid.drawPixel(1,4, BlueG);
   grid.drawPixel(1,7, BlueG);
   grid.drawPixel(0,3, BlueG);
   grid.drawPixel(0,5, BlueG);
   grid.drawPixel(0,6, BlueG);
   grid.drawPixel(4,5, Blue);
   grid.drawPixel(3,1, Blue);
   grid.drawPixel(3,4, Blue);
   grid.drawPixel(2,6, Blue);
   grid.drawPixel(1,2, Blue);
   grid.drawPixel(1,3, Blue);
   grid.drawPixel(0,0, Blue);
   grid.drawPixel(0,7, Blue);
   grid.show();
   delay(800);
   
   // Iteration 5 - 11 turn off, 7 turn blueG
   grid.drawPixel(4,0,0);
   grid.drawPixel(4,3,0);
   grid.drawPixel(4,6,0);
   grid.drawPixel(3,5,0);
   grid.drawPixel(2,1,0);
   grid.drawPixel(2,4,0);
   grid.drawPixel(2,7,0);
   grid.drawPixel(1,0,0);
   grid.drawPixel(1,6,0);
   grid.drawPixel(0,2,0);
   grid.drawPixel(0,4,0);
   grid.drawPixel(4,4, BlueG);
   grid.drawPixel(3,2, BlueG);
   grid.drawPixel(3,7, BlueG);
   grid.drawPixel(2,0, BlueG);
   grid.drawPixel(2,3, BlueG);
   grid.drawPixel(1,5, BlueG);
   grid.drawPixel(0,1, BlueG);
   grid.show();
   delay(800);

   // Iteration 6 - 14 turn off, 8 turn blueG
   grid.drawPixel(4,1,0);
   grid.drawPixel(4,2,0);
   grid.drawPixel(4,7,0);
   grid.drawPixel(3,0,0);
   grid.drawPixel(3,3,0);
   grid.drawPixel(3,6,0);
   grid.drawPixel(2,2,0);
   grid.drawPixel(2,5,0);
   grid.drawPixel(1,1,0);
   grid.drawPixel(1,4,0);
   grid.drawPixel(1,7,0);
   grid.drawPixel(0,3,0);
   grid.drawPixel(0,5,0);
   grid.drawPixel(0,6,0);
   grid.drawPixel(4,5, BlueG);
   grid.drawPixel(3,1, BlueG);
   grid.drawPixel(3,4, BlueG);
   grid.drawPixel(2,6, BlueG);
   grid.drawPixel(1,2, BlueG);
   grid.drawPixel(1,3, BlueG);
   grid.drawPixel(0,0, BlueG);
   grid.drawPixel(0,7, BlueG);
   grid.show();
   digitalWrite(LED_BUILTIN, HIGH);
   delay(800);

   // Iteration 7 - 7 turn off
   grid.drawPixel(4,4,0);
   grid.drawPixel(3,2,0);
   grid.drawPixel(3,7,0);
   grid.drawPixel(2,0,0);
   grid.drawPixel(2,3,0);
   grid.drawPixel(1,5,0);
   grid.drawPixel(0,1,0);
   grid.show();
   delay(800);

   // Iteration 8 - all off
   grid.fillScreen(grid.Color(0,0,0));    
   grid.show();
   delay(800); 

 }