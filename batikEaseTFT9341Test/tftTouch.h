// // Touch screen library with X Y and Z (pressure) readings as well
// // as oversampling to avoid 'bouncing'
// // This demo code returns raw readings, public domain

// #include <stdint.h>
// #include "TouchScreen.h"

// #define YP A2  // must be an analog pin, use "An" notation!
// #define XM A3  // must be an analog pin, use "An" notation!
// #define YM 8   // can be a digital pin
// #define XP 9   // can be a digital pin

// // For better pressure precision, we need to know the resistance
// // between X+ and X- Use any multimeter to read it
// // For the one we're using, its 300 ohms across the X plate

// // Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST, TFT_MISO);
// TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);



// void touchSetup(void)
// {
//   Serial.println("The grand finale: Touch mode!!!");
//   tft.fillScreen(ILI9341_BLACK);
//   //unsigned long start = micros();
//   tft.setCursor(0, 0);
//   tft.setTextColor(ILI9341_WHITE);  
//   tft.setTextSize(2);
//   tft.println("Touch Anywhere!");
// }


// void touchLoop(void)
// {
//   // a point object holds x y and z coordinates
//   TSPoint p = ts.getPoint();
  
//   // we have some minimum pressure we consider 'valid'
//   // pressure of 0 means no pressing!
//   if (p.z > ts.pressureThreshhold)   //useful in toggling a digital pin.
//   {
//      Serial.print("X = "); Serial.print(p.x);
//      Serial.print("\tY = "); Serial.print(p.y);
//      Serial.print("\tPressure = "); Serial.println(p.z);
//   }

//   delay(100);
//   //return micros() - start;
// }







// // void setup(void)
// // { Serial.begin(9600);}


// //void loop(void)
// // {
// //   // a point object holds x y and z coordinates
// //   TSPoint p = ts.getPoint();
  
// //   // we have some minimum pressure we consider 'valid'
// //   // pressure of 0 means no pressing!
// //   if (p.z > ts.pressureThreshhold) {
// //      Serial.print("X = "); Serial.print(p.x);
// //      Serial.print("\tY = "); Serial.print(p.y);
// //      Serial.print("\tPressure = "); Serial.println(p.z);
// //   }

// //   delay(100);
// // }