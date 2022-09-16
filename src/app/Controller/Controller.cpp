#include "Controller.h"

Controller::Controller(Service *serv, ClockService *clockServ, DHT11Service *dhtService)
{
    this->service = serv;
    this->clockService = clockServ;
    this->dhtService = dhtService;
    lightState = LIGHT_OFF;
}

Controller::~Controller()
{
}


void Controller::updateEvent(std::string strBtn)
{
    if (strBtn == "modeButton")
    {
        service->updateState("modeButton");
    }

     if (strBtn == "powerButton")
    {
        service->updateState("powerButton");
    }

    if(strBtn == "clockUpdate")
    {
        clockService->updateEvent();
    }
}

void Controller::updateTempHumid(DHT_Data dhtData)
{
    dhtService->updateTempHumid(dhtData);
    service->updateTempHumid(dhtData);
}