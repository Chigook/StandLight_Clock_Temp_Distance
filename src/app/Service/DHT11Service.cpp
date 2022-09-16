#include "DHT11Service.h"

DHT11Service::DHT11Service(DHT11View *dhtView)
{
    this->dhtView = dhtView;
}

DHT11Service::~DHT11Service()
{

}

void DHT11Service::updateTempHumid(DHT_Data dhtData)
{
    float temp, humid;
    temp = (float)dhtData.Temp + (float)(dhtData.TempDec/10.0);
    humid = (float)dhtData.RH + (float)(dhtData.RHDec/10.0);

    dhtView->setTempHumidData(temp, humid);
}