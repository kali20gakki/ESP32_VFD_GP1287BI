// #include <Arduino.h>
// #include <U8g2lib.h>
// #ifdef U8X8_HAVE_HW_SPI
// #include <SPI.h>
// #endif
// #ifdef U8X8_HAVE_HW_I2C
// #include <Wire.h>
// #endif
// #include "SHT31.h"

// SHT31 sht31 = SHT31();

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
//     u8g2.drawStr(107,20,"Draw String : ABCDabcd");
//     u8g2.drawStr(107,30,"Draw Number : 12345678");
//     u8g2.drawStr(107,40,"Draw Float  : 3.141592");


//     u8g2.setDrawColor(2);
//     u8g2.drawBox(108,2,80,10);
//     u8g2.drawBox(108,42,133,7);

//     u8g2.drawStr(107,10,"Color Invert");
// }

// // 星期一 MON 、星期二 TUE 、星期三 WED 、星期四 THU 、星期五 FRI 、星期六 SAT 、星期天 SUN

// String week[] = {
//   "MON", 
//   "TUE",
//   "WED",
//   "THU",
//   "FRI",
//   "SAT",
//   "SUN"
// };


// void draw_font(float temp, float hum){
//     u8g2.setFontMode(1);  // Transparent
//     u8g2.setDrawColor(1);

//     /* 时间 */
//     u8g2.drawLine(0,0,10,0);
//     u8g2.drawLine(0,0,0,10);

//     u8g2.drawLine(0,49 - 22,10,49 - 22);
//     u8g2.drawLine(0,40 - 22,0,49 - 22);

//     u8g2.drawLine(245 - 107,49 - 22,255 - 107,49 - 22);
//     u8g2.drawLine(255 - 107,40 - 22,255 - 107,49 - 22);

//     u8g2.drawLine(245 - 107,0,255 - 107,0);
//     u8g2.drawLine(255 - 107,0,255 - 107,10);

//     u8g2.setFont(u8g2_font_maniac_tf);
//     u8g2.drawStr(5,25,"18 : 25 : 12");

//     /* 温湿度 */

//     u8g2.setFont(u8g2_font_open_iconic_all_2x_t);
//     u8g2.drawGlyph(5, 50, 0x0100 + 3); // 温度
//     u8g2.drawGlyph(78, 50, 0x0090 + 8); // 湿度

//     auto temp_str = String(temp, 1);
//     auto hum_str = String(hum, 1);
//     u8g2.setFont(u8g2_font_crox5h_tf);
//     u8g2.drawStr(25,50, temp_str.c_str());
//     u8g2.drawStr(99,50, hum_str.c_str());

//     /* 日历 */
//     u8g2.drawBox(205,2,50,10);
//     u8g2.drawFrame(205,2,50,48);
//     u8g2.setFont(u8g2_font_6x12_tf);

//     u8g2.setDrawColor(2); 
//     u8g2.drawStr(207,10,"12"); // 月
//     u8g2.drawStr(237,10, week[2].c_str()); // 星期

//     u8g2.setFont(u8g2_font_calblk36_tr);
//     u8g2.drawStr(209, 44,"26"); // 日

//     /* PM2.5 */
//     u8g2.setDrawColor(1);
//     u8g2.setFont(u8g2_font_7x13_tn);
//     u8g2.drawFrame(153,2,48,48);
//     u8g2.drawLine(153,18,153 + 47,18);
//     u8g2.drawLine(153,18 + 16,153 + 47,18 + 16);
//     u8g2.drawStr(162, 15,"PM1.0"); // PM1.0
//     u8g2.drawStr(162, 15 + 16,"PM2.5"); // PM2.5
//     u8g2.drawStr(162, 15 + 32,"PM10"); // PM10

    
// }


// void setup(void) {

//   pinMode(FILMENT_EN, OUTPUT);
//   digitalWrite(FILMENT_EN, HIGH);


//   pinMode(LED_PIN, OUTPUT);
//   digitalWrite(LED_PIN, HIGH);

//   sht31.begin();

//   u8g2.begin();  
// }

// void loop(void) {
//   float temp = sht31.getTemperature();
//   float hum = sht31.getHumidity();

//   u8g2.firstPage();
//   do {
//     //draw_demo();
//     draw_font(temp, hum);
//   } while ( u8g2.nextPage() );
//   delay(1000);
// }
