#ifndef SETTINGS_H
#define SETTINGS_H

// Weather Settings
#define CITY_ID "1796236"  // 1796236 上海  1795565 SHENZHEN City https://openweathermap.org/current#cityid  (在这里可以查询城市代码)

// You can also use LAT,LON for your location instead of CITY_ID, but not both
#define LAT "31.230391" // 上海, Looked up on https://www.latlong.net/
#define LON "121.473701"

// 这个天气接口不好, 最低和最高温度总是一样, 3.0接口还要收费
// http://api.openweathermap.org/data/2.5/weather?id=1796236&lang=en&units=metric&appid=0d1949854101140caad159dc9a23ca86
#ifdef CITY_ID
  #define OPENWEATHERMAP_URL "http://api.openweathermap.org/data/2.5/weather?id={cityID}&lang={lang}&units={units}&appid={apiKey}"  //open weather api using city ID
#else
  #define OPENWEATHERMAP_URL "http://api.openweathermap.org/data/2.5/weather?lat={lat}&lon={lon}&lang={lang}&units={units}&appid={apiKey}"  //open weather api using lat lon
#endif

#define OPENWEATHERMAP_APIKEY "0d1949854101140caad159dc9a23ca86"  //use your own API key :)
#define TEMP_UNIT "metric"                                        // metric = Celsius , imperial = Fahrenheit
#define TEMP_LANG "en"
#define WEATHER_UPDATE_INTERVAL 30  // must be greater than 5, measured in minutes
// NTP Settings
#define NTP_SERVER "pool.ntp.org"
#define GMT_OFFSET_SEC 3600 * 8  // SHENZHEN UTC+8 = 3800 * 8  https://time.artjoey.com/cn/ (在这里可以查询时差)

/*
typedef struct watchySettings {
  // Weather Settings
  String cityID;
  String lat;
  String lon;
  String weatherAPIKey;
  String weatherURL;
  String weatherUnit;
  String weatherLang;
  int8_t weatherUpdateInterval;
  // NTP Settings
  String ntpServer;
  int gmtOffset;
  //
  bool vibrateOClock;
} watchySettings;
*/
watchySettings settings{
#ifdef CITY_ID
  .cityID = CITY_ID,
#endif
#ifdef LAT
  .lat = LAT,
  .lon = LON,
#endif
  .weatherAPIKey = OPENWEATHERMAP_APIKEY,
  .weatherURL = OPENWEATHERMAP_URL,
  .weatherUnit = TEMP_UNIT,
  .weatherLang = TEMP_LANG,
  .weatherUpdateInterval = WEATHER_UPDATE_INTERVAL,
  .ntpServer = NTP_SERVER,
  .gmtOffset = GMT_OFFSET_SEC,
  .vibrateOClock = true,
};

#endif
