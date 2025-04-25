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
      void showSensorWeather (weatherData *currentWeather);
      void drawWeatherIcon (int16_t weatherConditionCode);
};

#endif
