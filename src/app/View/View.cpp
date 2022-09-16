#include "View.h"
#include <wiringPi.h>

View::View(Led *led1, Led *led2, Led *led3, Led *led4, Led *led5, LCD *lcd)
{
    light1 = led1;
    light2 = led2;
    light3 = led3;
    light4 = led4;
    light5 = led5;
    lightState = LIGHT_OFF;
    temper = 0;
    this->lcd = lcd;
}


View::~View()
{

}

void View::setState(int state)
{
    lightState = state;
}

void View::setTempHumidData(float temp, float humid)
{
    temper= temp;
}

void View::checkTemp()
{
    char buff[30];
    int temp_state = 0;
    if(temper >= 26)
    {
        temp_state = 1;
    }
    else
    {
        temp_state = 0;
    }

    if(temp_state == 1){
        sprintf(buff,"Warning   ");
        lcd->WriteStringXY(1,9,buff);
        light1->Off();
        light2->Off();
        light3->Off();
        light4->Off();
        light5->Off();
    }
    else if (temp_state == 0)
    {
        lightView();
    }
}

void View::lightView()
{
    switch (lightState)
    {
        case LIGHT_OFF:
            lightOff();
        break;
        case LIGHT_1:
            lightOn_1();
        break;
        case LIGHT_2:
            lightOn_2();
        break;
        case LIGHT_3:
            lightOn_3();
        break;
        case LIGHT_4:
            lightOn_4();
        break;
        case LIGHT_5:
            lightOn_5();
        break;
    }
}

void View::lightOn_1()
{
    char buff[30];
    sprintf(buff," LED 1     ");
    lcd->WriteStringXY(1,9,buff);
    lcd->backLightOn();
    light1->On();
    light2->Off();
    light3->Off();
    light4->Off();
    light5->Off();
}

void View::lightOn_2()
{
    char buff[30];
    sprintf(buff," LED 2     ");
    lcd->WriteStringXY(1,9,buff);
    light1->On();
    light2->On();
    light3->Off();
    light4->Off();
    light5->Off();
}

void View::lightOn_3()
{
    char buff[30];
    sprintf(buff," LED 3     ");
    lcd->WriteStringXY(1,9,buff);
    light1->On();
    light2->On();
    light3->On();
    light4->Off();
    light5->Off();
}

void View::lightOn_4()
{
    char buff[30];
    sprintf(buff," LED 4     ");
    lcd->WriteStringXY(1,9,buff);
    light1->On();
    light2->On();
    light3->On();
    light4->On();
    light5->Off();
}

void View::lightOn_5()
{
    char buff[30];
    sprintf(buff," LED 5     ");
    lcd->WriteStringXY(1,9,buff);
    light1->On();
    light2->On();
    light3->On();
    light4->On();
    light5->On();
}

void View::lightOff()
{
    char buff[30];
    sprintf(buff,"LED off   ");
    lcd->WriteStringXY(1,9,buff);
    lcd->backLightOff();
    light1->Off();
    light2->Off();
    light3->Off();
    light4->Off();
    light5->Off();
}