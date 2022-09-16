#ifndef SERVICE_H
#define SERVICE_H

#include <string>
#include "View.h"
#include "LightState.h"
#include "DHT_Data.h"

#pragma once

class Service
{
private:
    int lightState;
    View *view;
    bool bDistanceLight;

public:
    Service(View *view);
    virtual ~Service();
    void updateState(std::string strState);
    void updateTempHumid(DHT_Data dhtData);
    void updateDistance(int distance);
};

#endif