// #ifdef U8X8_HAVE_HW_SPI
// #include <SPI.h>
// #endif
// #ifdef U8X8_HAVE_HW_I2C
// #include <Wire.h>
// #endif
// #include <Arduino.h>
// #include <SoftwareSerial.h>
// #define LENG 31 // 0x42 + 31 bytes equal to 32 bytes

// unsigned char buf[LENG];
// SoftwareSerial PMSerial(18, 17); // RX, TX
// int PM01Value = 0;               // define PM1.0 value of the air detector module
// int PM2_5Value = 0;              // define PM2.5 value of the air detector module
// int PM10Value = 0;               // define PM10 value of the air detector module

// char checkValue(unsigned char *thebuf, char leng)
// {
//     char receiveflag = 0;
//     int receiveSum = 0;

//     for (int i = 0; i < (leng - 2); i++)
//     {
//         receiveSum = receiveSum + thebuf[i];
//     }
//     receiveSum = receiveSum + 0x42;

//     if (receiveSum == ((thebuf[leng - 2] << 8) + thebuf[leng - 1])) // check the serial data
//     {
//         receiveSum = 0;
//         receiveflag = 1;
//     }
//     return receiveflag;
// }

// int transmitPM01(unsigned char *thebuf)
// {
//     int PM01Val;
//     PM01Val = ((thebuf[3] << 8) + thebuf[4]); // count PM1.0 value of the air detector module
//     return PM01Val;
// }

// // transmit PM Value to PC
// int transmitPM2_5(unsigned char *thebuf)
// {
//     int PM2_5Val;
//     PM2_5Val = ((thebuf[5] << 8) + thebuf[6]); // count PM2.5 value of the air detector module
//     return PM2_5Val;
// }

// // transmit PM Value to PC
// int transmitPM10(unsigned char *thebuf)
// {
//     int PM10Val;
//     PM10Val = ((thebuf[7] << 8) + thebuf[8]); // count PM10 value of the air detector module
//     return PM10Val;
// }

// void setup()
// {
//     Serial.begin(115200); // 使用串口0
//     PMSerial.begin(9600);
//     PMSerial.setTimeout(1500); // 设置超时时间为1500毫秒（大于传感器传送数据周期1秒）
// }

// void loop()
// {
//     if (PMSerial.find(0x42))
//     { // 检测到0x42时，开始读取
//         PMSerial.readBytes(buf, LENG);

//         if (buf[0] == 0x4d)
//         {
//             if (checkValue(buf, LENG))
//             {
//                 PM01Value = transmitPM01(buf);   // count PM1.0 value of the air detector module
//                 PM2_5Value = transmitPM2_5(buf); // count PM2.5 value of the air detector module
//                 PM10Value = transmitPM10(buf);   // count PM10 value of the air detector module
//             }
//         }
//     }

//     static unsigned long OledTimer = millis();
//     if (millis() - OledTimer >= 1000)
//     {
//         OledTimer = millis();

//         Serial.print("PM1.0: ");
//         Serial.print(PM01Value);
//         Serial.println("  ug/m3");

//         Serial.print("PM2.5: ");
//         Serial.print(PM2_5Value);
//         Serial.println("  ug/m3");

//         Serial.print("PM1 0: ");
//         Serial.print(PM10Value);
//         Serial.println("  ug/m3");
//         Serial.println();
//     }
// }