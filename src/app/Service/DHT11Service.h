#ifndef DHT11SERVICE_H
#define DHT11SERVICE_H

#include "DHT_Data.h"
#include "DHT11View.h"

class DHT11Service
{
private:
    DHT11View *dhtView;


public:
    DHT11Service(DHT11View *dhtView);
    ~DHT11Service();
    void updateTempHumid(DHT_Data dhtData);


};

#endif