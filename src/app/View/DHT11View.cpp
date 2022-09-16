#include "DHT11View.h"

DHT11View::DHT11View(LCD *lcd, Led *led1, Led *led2, Led *led3, Led *led4, Led *led5)
{
    this->lcd = lcd;
    this->light1 = led1;
    this->light2 = led2;
    this->light3 = led3;
    this->light4 = led4;
    this->light5 = led5;
}

DHT11View::~DHT11View()
{

}

void DHT11View::setTempHumidData(float temp, float humid)
{
    char buff[30];
    sprintf(buff, "  %.1fC  %.1f%%", temp, humid);
    lcd->WriteStringXY(0, 0, buff);
    printf("%s\n", buff);
}
