#include "ui.h"

// 星期一 MON 、星期二 TUE 、星期三 WED 、星期四 THU 、星期五 FRI 、星期六 SAT 、星期天 SUN
String week[] = {
    "MON",
    "TUE",
    "WED",
    "THU",
    "FRI",
    "SAT",
    "SUN"};

U8G2_GP1287AI_256X50_F_4W_SW_SPI u8g2(U8G2_R0, CLK, DATA, CS, DC, RST);
uint8_t u8log_buffer[U8LOG_WIDTH * U8LOG_HEIGHT];
U8G2LOG u8g2log;

static bool change_air_flag = true;

void show_connection_log(void)
{
    u8g2log.print(".");
    // print the log window together with a title
    u8g2.firstPage();
    do
    {
        u8g2.setFont(u8g2_font_6x13_tr); // font for the title
        u8g2.setCursor(0, 13);
        u8g2.print("Waitting For WiFi Connection"); // output title
        u8g2.setFont(u8g2_font_5x7_tr);             // set the font for the terminal window
        u8g2.drawLog(0, 23, u8g2log);               // draw the log content on the display
    } while (u8g2.nextPage());
}

void draw_demo(void)
{
    u8g2.setFontMode(1); // Transparent
    u8g2.setDrawColor(1);

    u8g2.drawLine(0, 0, 10, 0);
    u8g2.drawLine(0, 0, 0, 10);

    u8g2.drawLine(0, 49, 10, 49);
    u8g2.drawLine(0, 40, 0, 50);

    u8g2.drawLine(245, 49, 255, 49);
    u8g2.drawLine(255, 40, 255, 50);

    u8g2.drawLine(245, 0, 255, 0);
    u8g2.drawLine(255, 0, 255, 10);

    u8g2.drawFrame(5, 16, 30, 30);

    u8g2.drawLine(37, 45, 68, 45);
    u8g2.drawLine(52, 15, 37, 45);
    u8g2.drawLine(52, 15, 68, 45);

    u8g2.drawCircle(83, 30, 15, U8G2_DRAW_ALL);

    u8g2.setFont(u8g2_font_6x12_tf);
    u8g2.drawStr(5, 10, "GP1287BI 256x50");
    u8g2.drawStr(200, 10, "By U8G2");
    u8g2.drawStr(200, 10, "By U8G2");
    u8g2.drawStr(107, 20, "Draw String : ABCDabcd");
    u8g2.drawStr(107, 30, "Draw Number : 12345678");
    u8g2.drawStr(107, 40, "Draw Float  : 3.141592");

    u8g2.setDrawColor(2);
    u8g2.drawBox(108, 2, 80, 10);
    u8g2.drawBox(108, 42, 133, 7);

    u8g2.drawStr(107, 10, "Color Invert");
}

String align_int2str(int x)
{
    String res;
    if (x <= 9)
    {
        res = "0" + String(x);
    }
    else
    {
        res = String(x);
    }

    return res;
}

void draw_ui(float temp, float hum, struct tm t, int pm1_0, int pm2_5, int pm10)
{
    u8g2.setFontMode(1); // Transparent
    u8g2.setDrawColor(1);

    /* 温湿度 */
    u8g2.setFont(u8g2_font_open_iconic_all_2x_t);
    u8g2.drawGlyph(5, 50, 0x0100 + 3);  // 温度
    u8g2.drawGlyph(78, 50, 0x0090 + 8); // 湿度

    auto temp_str = String(temp, 1);
    auto hum_str = String(hum, 1);
    u8g2.setFont(u8g2_font_crox5h_tf);
    u8g2.drawStr(25, 50, temp_str.c_str());
    u8g2.drawStr(99, 50, hum_str.c_str());

    /* 日历 */
    u8g2.drawBox(205, 2, 50, 10);
    u8g2.drawFrame(205, 2, 50, 48);
    u8g2.setFont(u8g2_font_6x12_tf);

    u8g2.setDrawColor(2);
    auto month = String(t.tm_mon + 1);
    String day = align_int2str(t.tm_mday);

    // u8g2.drawStr(207, 10, "12");            // 月
    u8g2.drawStr(207, 10, month.c_str());           // 月
    u8g2.drawStr(237, 10, week[t.tm_wday].c_str()); // 星期

    u8g2.setFont(u8g2_font_calblk36_tr);

    // u8g2.drawStr(209, 44, "26"); // 日
    u8g2.drawStr(209, 44, day.c_str()); // 日

    /* 空气质量 */
    u8g2.setDrawColor(1);
    u8g2.drawFrame(153, 2, 48, 48);
    u8g2.drawLine(153, 18, 153 + 47, 18);
    u8g2.drawLine(153, 18 + 16, 153 + 47, 18 + 16);
    u8g2.setFont(u8g2_font_7x13B_tf);
    if (change_air_flag)
    {
        u8g2.drawStr(158, 15, (String(pm1_0) + " ug").c_str());      // PM1.0
        u8g2.drawStr(158, 15 + 16, (String(pm2_5) + " ug").c_str()); // PM2.5
        u8g2.drawStr(158, 15 + 32, (String(pm10) + " ug").c_str());  // PM10
        change_air_flag = false;
    }
    else
    {
        u8g2.drawStr(160, 15, "PM1.0");      // PM1.0
        u8g2.drawStr(160, 15 + 16, "PM2.5"); // PM2.5
        u8g2.drawStr(160, 15 + 32, "PM10");  // PM10
        change_air_flag = true;
    }
}

void draw_time(struct tm t)
{
    /* 时间 */
    // if (t.tm_hour >= 10 && t.tm_hour / 10 == 2){
    //     u8g2.drawLine(0, 0, 10, 0); // 左上角
    //     u8g2.drawLine(0, 0, 0, 10);

    //     u8g2.drawLine(0, 49 - 18, 10, 49 - 18); // 左下角
    //     u8g2.drawLine(0, 40 - 18, 0, 49 - 18);
    // } else {
    //     u8g2.drawLine(5, 0, 15, 0); // 左上角
    //     u8g2.drawLine(5, 0, 5, 10);

    //     u8g2.drawLine(5, 49 - 18, 15, 49 - 18); // 左下角
    //     u8g2.drawLine(5, 40 - 18, 5, 49 - 18);
    // }

    // u8g2.drawLine(245 - 109, 49 - 18, 255 - 109, 49 - 18); // 右上角
    // u8g2.drawLine(255 - 109, 40 - 18, 255 - 109, 49 - 18);

    // u8g2.drawLine(245 - 109, 0, 255 - 109, 0); // 右下角
    // u8g2.drawLine(255 - 109, 0, 255 - 109, 10);

    u8g2.setFont(u8g2_font_freedoomr25_mn);

    // HH:mm:ss
    char h1 = (t.tm_hour >= 10 ? t.tm_hour / 10 : 0) + '0';
    char h2 = (t.tm_hour >= 10 ? t.tm_hour % 10 : t.tm_hour) + '0';

    char m1 = (t.tm_min >= 10 ? t.tm_min / 10 : 0) + '0';
    char m2 = (t.tm_min >= 10 ? t.tm_min % 10 : t.tm_min) + '0';

    char s1 = (t.tm_sec >= 10 ? t.tm_sec / 10 : 0) + '0';
    char s2 = (t.tm_sec >= 10 ? t.tm_sec % 10 : t.tm_sec) + '0';

    u8g2.drawStr(4, 30, String(t.tm_hour >= 10 ? t.tm_hour / 10 : 0).c_str());
    u8g2.drawStr(24, 30, String(t.tm_hour >= 10 ? t.tm_hour % 10 : t.tm_hour).c_str());
    u8g2.drawStr(41, 27, ":");
    u8g2.drawStr(54, 30, String(t.tm_min >= 10 ? t.tm_min / 10 : 0).c_str());
    u8g2.drawStr(74, 30, String(t.tm_min >= 10 ? t.tm_min % 10 : t.tm_min).c_str());
    u8g2.drawStr(91, 27, ":");
    u8g2.drawStr(104, 30, String(t.tm_sec >= 10 ? t.tm_sec / 10 : 0).c_str());
    u8g2.drawStr(124, 30, String(t.tm_sec >= 10 ? t.tm_sec % 10 : t.tm_sec).c_str());
}

bool ui_run(short *a, short *a_trg, short v)
{
    if (*a < *a_trg)
    {
        *a += v;
    }
    else if (*a > *a_trg)
    {
        *a -= v;
    }
    else
    {
        return false;
    }
    return true;
}

bool roll_run(short *value, short *target_value, short velocity)
{
    if (*value < *target_value && (*value + velocity) <= *target_value){
        *value += velocity;
    } else if(*value > *target_value && (*value + velocity) >= *target_value){
        *value -= velocity;
    } else if(*value < *target_value && (*value + velocity) > *target_value){
        *value = *target_value;
    } else if(*value > *target_value && (*value + velocity) < *target_value){
        *value -= velocity;
    } 
    return true;
}
short s2_cur_y = 30;
short s2_target_y = 5;

void draw_roll_time(struct tm t)
{
    u8g2.setFont(u8g2_font_freedoomr25_mn);

    // HH:mm:ss
    char h1 = (t.tm_hour >= 10 ? t.tm_hour / 10 : 0) + '0';
    char h2 = (t.tm_hour >= 10 ? t.tm_hour % 10 : t.tm_hour) + '0';

    char m1 = (t.tm_min >= 10 ? t.tm_min / 10 : 0) + '0';
    char m2 = (t.tm_min >= 10 ? t.tm_min % 10 : t.tm_min) + '0';

    char s1 = (t.tm_sec >= 10 ? t.tm_sec / 10 : 0) + '0';
    char s2 = (t.tm_sec >= 10 ? t.tm_sec % 10 : t.tm_sec) + '0';

    u8g2.drawStr(4, 30, String(t.tm_hour >= 10 ? t.tm_hour / 10 : 0).c_str());
    u8g2.drawStr(24, 30, String(t.tm_hour >= 10 ? t.tm_hour % 10 : t.tm_hour).c_str());
    u8g2.drawStr(41, 27, ":");
    u8g2.drawStr(54, 30, String(t.tm_min >= 10 ? t.tm_min / 10 : 0).c_str());
    u8g2.drawStr(74, 30, String(t.tm_min >= 10 ? t.tm_min % 10 : t.tm_min).c_str());
    u8g2.drawStr(91, 27, ":");
    u8g2.drawStr(104, 30, String(t.tm_sec >= 10 ? t.tm_sec / 10 : 0).c_str());
    // u8g2.drawStr(124, 30, String(t.tm_sec >= 10 ? t.tm_sec % 10 : t.tm_sec).c_str());


    short s2_cur_num = t.tm_sec >= 10 ? t.tm_sec % 10 : t.tm_sec;
    u8g2.drawStr(124, s2_cur_y, String(s2_cur_num).c_str());
    short s2_next_num = s2_cur_num >= 9 ? 0 : s2_cur_num + 1;
    short s2_next_y = s2_cur_y + 30;
    u8g2.drawStr(124, s2_next_y, String(s2_next_num).c_str());
    if (!ui_run(&s2_cur_y, &s2_target_y, 2))
    {
        s2_cur_y = 30;
    }
    Serial.print("s2_cur_num = " + String(s2_cur_num));
    Serial.print(" ");
    Serial.println("s2_cur_y = " + String(s2_cur_y));
    Serial.print("s2_next_num = " + String(s2_next_num));
    Serial.print(" ");
    Serial.println("s2_next_y = " + String(s2_next_y));
    Serial.println("------------------------");
}