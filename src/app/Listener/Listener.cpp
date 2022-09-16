#include "Listener.h"

Listener::Listener(Button *modeButton, Button *powerButton, Controller *control, ClockCheck *clock, DHT11 *dht11)
{
    this->modeButton = modeButton;
    this->powerButton = powerButton;
    controller = control;
    clockCheck = clock;
    this->dht11 = dht11;
}

Listener::~Listener()
{
}

void Listener::checkEvent()
{
    if (modeButton->getState() == RELEASE_ACTIVE)
    {
        controller->updateEvent("modeButton");
    }

    if (powerButton->getState() == RELEASE_ACTIVE)
    {
        controller->updateEvent("powerButton");
    }

    if(clockCheck->isUpdate())
    {
        controller->updateEvent("clockUpdate");
    }

    static unsigned int prevTempHumidTime = 0;
    if(millis() - prevTempHumidTime > 2000)
    {
        prevTempHumidTime = millis();
        DHT_Data dhtData = dht11->readData();
        if(!dhtData.error){
            controller->updateTempHumid(dhtData);
        }
    }
}