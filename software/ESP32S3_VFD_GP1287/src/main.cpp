#include <Arduino.h>
#include <WiFi.h>
#include "ui.h"
#include "SHT31.h"
#include "pm25_sensor.h"

const char *ssid = "208";             // wifi nane
const char *password = "13988932779"; // wifi password

//-----------网络时间获取-----------//
const char *ntpServer = "ntp.aliyun.com"; // 网络时间服务器
// 时区设置函数，东八区（UTC/GMT+8:00）写成8*3600
const long gmtOffset_sec = 8 * 3600;
const int daylightOffset_sec = 0; // 夏令时填写3600，否则填0

SHT31 sht31 = SHT31();
struct tm timeinfo;

void getTime(struct tm *t)
{
    if (!getLocalTime(t))
    {
        Serial.println("Failed to obtain time");
        return;
    }
    // Serial.println(t, "%F %T %A"); // 格式化输出
}

const uint8_t tile_area_x_pos = 0;	// Update area left position (in tiles)
const uint8_t tile_area_y_pos = 0;	// Update area upper position (distance from top in tiles)
const uint8_t tile_area_width = 18;
const uint8_t tile_area_height = 4;	// this will allow cour18 chars to fit into the area

const u8g2_uint_t pixel_area_x_pos = tile_area_x_pos*8;
const u8g2_uint_t pixel_area_y_pos = tile_area_y_pos*8;
const u8g2_uint_t pixel_area_width = tile_area_width*8;
const u8g2_uint_t pixel_area_height = tile_area_height*8;

void setup(void)
{
    pinMode(FILMENT_EN, OUTPUT);
    digitalWrite(FILMENT_EN, HIGH);

    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, HIGH);

    u8g2.begin();
    u8g2log.begin(U8LOG_WIDTH, U8LOG_HEIGHT, u8log_buffer);
    u8g2log.setLineHeightOffset(0); // set extra space between lines in pixel, this can be negative
    u8g2log.setRedrawMode(0);       // 0: Update screen with newline, 1: Update screen for every char

    sht31.begin();

    PMSerial.begin(9600);
    PMSerial.setTimeout(1500); // 设置超时时间为1500毫秒（大于传感器传送数据周期1秒）

    Serial.begin(115200);

    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(100);
        Serial.print(".");
        show_connection_log();
    }
    Serial.println("WiFi connected!");

    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);

    u8g2.clearDisplay();
}


void loop(void)
{  
    u8g2.clearBuffer();
    getTime(&timeinfo);

    u8g2.drawFrame(pixel_area_x_pos-1, pixel_area_y_pos-1, pixel_area_width+2, pixel_area_height+2);
  
    draw_roll_time(timeinfo);

    //u8g2.sendBuffer();
    u8g2.updateDisplayArea(tile_area_x_pos, tile_area_y_pos, tile_area_width, tile_area_height);
    delay(100);
}