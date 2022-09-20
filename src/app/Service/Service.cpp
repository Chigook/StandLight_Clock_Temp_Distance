#include "Service.h"

Service::Service(View *view)
{
    this->view = view;
    lightState = LIGHT_OFF;
    bDistanceLight = false;
    int distanceOffCounter = 0;
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
            if(bDistanceLight){   // 거리 범위 이내
                view->setState(lightState);
            }
            else{   //거리 범위 밖
                view->setState(LIGHT_OFF);
            }
        break;

        case LIGHT_2:
            if (strState == "modeButton") {
                lightState = LIGHT_3;
            }
            if (strState == "powerButton") {
                lightState = LIGHT_OFF;
            }
            if(bDistanceLight){   // 거리 범위 이내
                view->setState(lightState);
            }
            else{   //거리 범위 밖
                view->setState(LIGHT_OFF);
            }
        break;

        case LIGHT_3:
            if (strState == "modeButton") {
                lightState = LIGHT_4;
            }
            if (strState == "powerButton") {
                lightState = LIGHT_OFF;
            }
            if(bDistanceLight){   // 거리 범위 이내
                view->setState(lightState);
            }
            else{   //거리 범위 밖
                view->setState(LIGHT_OFF);
            }
        break;

        case LIGHT_4:
            if (strState == "modeButton") {
                lightState = LIGHT_5;
            }
            if (strState == "powerButton") {
                lightState = LIGHT_OFF;
            }
            if(bDistanceLight){   // 거리 범위 이내
                view->setState(lightState);
            }
            else{   //거리 범위 밖
                view->setState(LIGHT_OFF);
            }
        break;

        case LIGHT_5:
            if (strState == "modeButton") {
                lightState = LIGHT_OFF;
            }
            if (strState == "powerButton") {
                lightState = LIGHT_OFF;
            }
            if(bDistanceLight){   // 거리 범위 이내
                view->setState(lightState);
            }
            else{   //거리 범위 밖
                view->setState(LIGHT_OFF);
            }
        break;
    }
}

void Service::updateDistance(int distance)
{
    if(distance < 0 || distance  > 100)
    {
        distanceOffCounter++;
        if (distanceOffCounter > 10)
        {
            bDistanceLight = false; // Light Off
            view->setState(LIGHT_OFF);
        }
    }
    else
    {
        distanceOffCounter = 0;
        bDistanceLight = true; // Light On
        view->setState(lightState);
    }

    printf("distance : %d, %d\n", distance, bDistanceLight);
}