#ifndef __PM25_SENSOR_H__
#define __PM25_SENSOR_H__

#include <Arduino.h>
#include <SoftwareSerial.h>

#define LENG 31 // 0x42 + 31 bytes equal to 32 bytes

extern unsigned char buf[LENG];
extern SoftwareSerial PMSerial; // RX, TX
extern int PM1_0Value;               // define PM1.0 value of the air detector module
extern int PM2_5Value;              // define PM2.5 value of the air detector module
extern int PM10Value;               // define PM10 value of the air detector module

char checkValue(unsigned char *thebuf, char leng);
int transmitPM01(unsigned char *thebuf);
int transmitPM2_5(unsigned char *thebuf);
int transmitPM10(unsigned char *thebuf);
void get_air_value(void);

#endif