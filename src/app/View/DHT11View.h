#ifndef DHT11VIEW_H
#define DHT11VIEW_H

#include "LCD.h"
#include <string>
#include "Led.h"
#include "LightState.h"

class DHT11View
{
private:
    LCD *lcd;
    Led *light1;
    Led *light2;
    Led *light3;
    Led *light4;
    Led *light5;

public:
    DHT11View(LCD *lcd, Led *led1, Led *led2, Led *led3, Led *led4, Led *led5);
    ~DHT11View();
    void setTempHumidData(float temp, float humid);
    void warningLightoff();
};

#endif