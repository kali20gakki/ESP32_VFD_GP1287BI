// #include <WiFi.h>
// #ifdef U8X8_HAVE_HW_SPI
// #include <SPI.h>
// #endif
// #ifdef U8X8_HAVE_HW_I2C
// #include <Wire.h>
// #endif
// const char* ssid = "208"; //wifi nane
// const char* password = "13988932779"; // wifi password

// //-----------网络时间获取-----------//
// const char *ntpServer = "ntp.aliyun.com"; //网络时间服务器
// //时区设置函数，东八区（UTC/GMT+8:00）写成8*3600
// const long gmtOffset_sec = 8 * 3600;    
// const int daylightOffset_sec = 0;   //夏令时填写3600，否则填0

// void printLocalTime()
// {
//     struct tm timeinfo;
//     if (!getLocalTime(&timeinfo))
//     {
//         Serial.println("Failed to obtain time");
//         return;
//     }
//     Serial.println(&timeinfo, "%F %T %A"); // 格式化输出
// }

// void setup()
// {
//     Serial.begin(115200);
//     Serial.println();

//     WiFi.begin(ssid, password);
//     while (WiFi.status() != WL_CONNECTED)
//     {
//         delay(500);
//         Serial.print(".");
//     }
//     Serial.println("WiFi connected!");

//     // 从网络时间服务器上获取并设置时间
//     // 获取成功后芯片会使用RTC时钟保持时间的更新
//     configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
//     printLocalTime();

//     // WiFi.disconnect(true);
//     // WiFi.mode(WIFI_OFF);
//     // Serial.println("WiFi disconnected!");
// }

// void loop()
// {
//     delay(1000);
//     printLocalTime();
// }
