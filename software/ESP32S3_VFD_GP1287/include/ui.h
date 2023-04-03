#ifndef __UI_H__
#define __UI_H__

#include <U8g2lib.h>
#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

#define U8LOG_WIDTH 128
#define U8LOG_HEIGHT 50


/* VFD 引脚定义 */
#define CLK 12
#define DATA 11
#define CS 10
#define DC 14
#define RST 9
#define FILMENT_EN 13

#define LED_PIN 45

extern U8G2_GP1287AI_256X50_F_4W_SW_SPI u8g2;
extern U8G2LOG u8g2log;
extern uint8_t u8log_buffer[U8LOG_WIDTH * U8LOG_HEIGHT];

void draw_demo(void);
void draw_ui(float temp, float hum, struct tm t, int pm1_0, int pm2_5, int pm10);
void show_connection_log(void);
void draw_time(struct tm t);
void draw_roll_time(struct tm t);
 
#endif