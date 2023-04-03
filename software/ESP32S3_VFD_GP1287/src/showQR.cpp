// #include <Arduino.h>
// #include <WiFi.h>
// #include "ui.h"
// #include <qrcode.h>

// #define SIZE 8
// QRCode qrcode_show;

// char *playload = "X-HM://0052B0Z1DHSPN";

// void show_qrcode(char *str_qrcode);

// void setup(void)
// {
//     pinMode(FILMENT_EN, OUTPUT);
//     digitalWrite(FILMENT_EN, HIGH);

//     pinMode(LED_PIN, OUTPUT);
//     digitalWrite(LED_PIN, HIGH);

//     u8g2.begin();

//     show_qrcode(playload);
// }

// void loop(void)
// {

//     delay(1000);
// }

// void show_qrcode(char *str_qrcode, uint8_t x0, uint8_t y0)
// {
//     uint8_t qrcodeData[qrcode_getBufferSize(SIZE)];
//     qrcode_initText(&qrcode_show, qrcodeData, SIZE, ECC_LOW, str_qrcode);

//     // start draw
//     u8g2.firstPage();
//     do
//     {
//         // get QR code pixels in a loop
//         for (uint8_t y = 0; y < qrcode_show.size; y++)
//         {
//             for (uint8_t x = 0; x < qrcode_show.size; x++)
//             {
//                 // Check this point is black or white
//                 if (qrcode_getModule(&qrcode_show, x, y))
//                 {
//                     u8g2.setColorIndex(1);
//                 }
//                 else
//                 {
//                     u8g2.setColorIndex(0);
//                 }

//                 u8g2.drawPixel(x0 + x, y0 + y);
//                 u8g2.drawPixel(x0 + x + 1, y0 + y);
//                 u8g2.drawPixel(x0 + x, y0 + y + 1);
//                 u8g2.drawPixel(x0 + x + 1, y0 + y + 1);
//             }
//         }
//     } while (u8g2.nextPage());
// }
