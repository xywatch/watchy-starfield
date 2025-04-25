#ifndef WATCHY_7_SEG_H
#define WATCHY_7_SEG_H
#include <math.h>
#include <Watchy.h>
#include "Dusk2Dawn.h"
#include "moonPhaser.h"
#include "Seven_Segment10pt7b.h"
#include "DSEG7_Classic_Bold_25.h"
#include "DSEG7_Classic_Regular_39.h"
#include "icons.h"

typedef struct weatherData2 {
  double_t temperature;
  int16_t weatherConditionCode;
  bool isMetric;
  // String weatherDescription; // 不能用String, 会在deep sleep丢失
  char weatherDescription[20];
  char city[20];
  bool external;
  tmElements_t sunrise;
  tmElements_t sunset;
  double_t minTemp; // 不能用float
  double_t maxTemp;
} weatherData2;

class Watchy7SEG : public Watchy{
    using Watchy::Watchy;
    public:
        void drawWatchFace();
        
        void drawTime();
        void drawDate();
        void drawSteps();

        void drawBattery();

        void drawFiel();
        void drawMoon();

        void drawSun();
        virtual void handleButtonPress();

        void showWeather();
        void drawWeather();

        // void drawEva();
        // void drawLine();
    private:
      void showSensorWeather ();
      void drawWeatherIcon (int16_t weatherConditionCode);
      weatherData2 getWeatherData2();
      weatherData2 _getWeatherData2(String cityID, String lat, String lon, String units, String lang,
                             String url, String apiKey, uint8_t updateInterval); 
};

#endif
