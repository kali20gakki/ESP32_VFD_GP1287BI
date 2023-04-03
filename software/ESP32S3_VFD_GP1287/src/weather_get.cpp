// #include <WiFi.h>
// #ifdef U8X8_HAVE_HW_SPI
// #include <SPI.h>
// #endif
// #ifdef U8X8_HAVE_HW_I2C
// #include <Wire.h>
// #endif
// #include <ArduinoJson.h>
// #include <HTTPClient.h>
 
// const char * ID = "208";
// const char * PASSWORD = "13988932779";
 
// //天气相关参数
// String API = "SLyrtxKko1KQbiFOL";
// String WeatherURL = "";
// String CITY = "曲靖";
// String url_xinzhi = "";
// String Weather = "0";
 
// long sum = 0;
 
// /* 创建实例 */
 
// HTTPClient http;
 
// String GitURL(String api,String city)
// {
//   url_xinzhi =  "https://api.seniverse.com/v3/weather/now.json?key=";
//   url_xinzhi += api;
//   url_xinzhi += "&location=";
//   url_xinzhi += city;
//   url_xinzhi += "&language=zh-Hans&unit=c";
//   return url_xinzhi;
// }
 
// void ParseWeather(String url)
// {  
//   DynamicJsonDocument doc(1024); //分配内存,动态
//   http.begin(url);
 
//   int httpGet = http.GET();
//   if(httpGet > 0)
//   {
//     Serial.printf("HTTPGET is %d",httpGet);
    
//     if(httpGet == HTTP_CODE_OK)
//     {
//       String json = http.getString();
//       Serial.println(json);
      
//       deserializeJson(doc, json);
      
//       Weather = doc["results"][0]["now"]["text"].as<String>();  
//     }
//     else
//     {
//       Serial.printf("ERROR1!!");
//     }
//   }
//   else
//   {
//     Serial.printf("ERROR2!!");
//   }
//   http.end();
// }
 
// void setup() 
// {
//   Serial.begin(115200);
 
//   //==================wifi连接==================
  
//   Serial.println("WiFi:");
//   Serial.println(ID);
//   Serial.println("PASSWORLD:");
//   Serial.println(PASSWORD);
  
//   WiFi.begin(ID,PASSWORD);
  
//   while(WiFi.status()!=WL_CONNECTED)
//   {
//     delay(500);
//     Serial.println("正在连接...");
//   }
 
//   Serial.println("连接成功！");
//   //==================wifi连接==================
  
//   WeatherURL = GitURL(API,CITY); 
  
// }
 
// void loop() 
// {
//   Serial.println("连接成功！");
//   ParseWeather(WeatherURL);
//   Serial.println(Weather);
//   Serial.print("执行次数: ");
//   Serial.println(sum);
//   sum ++;
//   delay(50000);  
// }