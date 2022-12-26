#include <Arduino.h>
#include <U8g2lib.h>
#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif


// /* VFD 引脚定义 */
// #define CLK 12
// #define DATA 11
// #define CS 10
// #define DC 14
// #define RST 9
// #define FILMENT_EN 13

// #define LED_PIN 45


// U8G2_GP1287AI_256X50_F_4W_SW_SPI u8g2(U8G2_R0, CLK, DATA, CS, DC, RST);


// void draw_demo(void)
// {
//     u8g2.setFontMode(1);  // Transparent
//     u8g2.setDrawColor(1);

//     u8g2.drawLine(0,0,10,0);
//     u8g2.drawLine(0,0,0,10);

//     u8g2.drawLine(0,49,10,49);
//     u8g2.drawLine(0,40,0,50);

//     u8g2.drawLine(245,49,255,49);
//     u8g2.drawLine(255,40,255,50);

//     u8g2.drawLine(245,0,255,0);
//     u8g2.drawLine(255,0,255,10);

//     u8g2.drawFrame(5,16,30,30);

//     u8g2.drawLine(37,45,68,45);
//     u8g2.drawLine(52,15,37,45);
//     u8g2.drawLine(52,15,68,45);

//     u8g2.drawCircle(83,30,15,U8G2_DRAW_ALL);

//     u8g2.setFont(u8g2_font_6x12_tf);
//     u8g2.drawStr(5,10,"GP1287BI 256x50");
//     u8g2.drawStr(200,10,"By U8G2");
//     u8g2.drawStr(200,10,"By U8G2");
//     u8g2.drawStr(110,20,"Draw String : ABCDabcd");
//     u8g2.drawStr(110,30,"Draw Number : 12345678");
//     u8g2.drawStr(110,40,"Draw Float  : 3.141592");


//     u8g2.setDrawColor(2);
//     u8g2.drawBox(108,2,80,10);
//     u8g2.drawBox(108,42,133,7);

//     u8g2.drawStr(110,10,"Color Invert");
// }

// void setup(void) {

//   pinMode(FILMENT_EN, OUTPUT);
//   digitalWrite(FILMENT_EN, HIGH);


//   pinMode(LED_PIN, OUTPUT);
//   digitalWrite(LED_PIN, HIGH);

//   u8g2.begin();  
// }

// void loop(void) {
//   u8g2.firstPage();
//   do {
//     draw_demo();
//   } while ( u8g2.nextPage() );
// }
