#include <OneWire.h>
#include <DallasTemperature.h>

class TemperatureRepository
{
private:
    int pin;
    OneWire oneWire;
    DallasTemperature dallasTemperature;

public:
    TemperatureRepository(int pin);

    void init();

    float measureTemperature();
};
