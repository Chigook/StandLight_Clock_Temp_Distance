#include "Service.h"

Service::Service(View *view)
{
    this->view = view;
    lightState = LIGHT_OFF;
}

Service::~Service()
{

}

void Service::updateTempHumid(DHT_Data dhtData)
{
    float temp, humid;
    temp = (float)dhtData.Temp + (float)(dhtData.TempDec/10.0);
    humid = (float)dhtData.RH + (float)(dhtData.RHDec/10.0);
    view->setTempHumidData(temp, humid);
}

void Service::updateState(std::string strState)
{
    switch (lightState)
    {
        case LIGHT_OFF:
            if (strState == "modeButton") {
                lightState = LIGHT_1;
                view->setState(lightState);
            }
        break;

        case LIGHT_1:
            if (strState == "modeButton") {
                lightState = LIGHT_2;
            }
            if (strState == "powerButton") {
                lightState = LIGHT_OFF;
            }
            view->setState(lightState);
        break;

        case LIGHT_2:
            if (strState == "modeButton") {
                lightState = LIGHT_3;
            }
            if (strState == "powerButton") {
                lightState = LIGHT_OFF;
            }
            view->setState(lightState);
        break;

        case LIGHT_3:
            if (strState == "modeButton") {
                lightState = LIGHT_4;
            }
            if (strState == "powerButton") {
                lightState = LIGHT_OFF;
            }
            view->setState(lightState);
        break;

        case LIGHT_4:
            if (strState == "modeButton") {
                lightState = LIGHT_5;
            }
            if (strState == "powerButton") {
                lightState = LIGHT_OFF;
            }
            view->setState(lightState);
        break;

        case LIGHT_5:
            if (strState == "modeButton") {
                lightState = LIGHT_OFF;
            }
            if (strState == "powerButton") {
                lightState = LIGHT_OFF;
            }
            view->setState(lightState);
        break;
    }
}