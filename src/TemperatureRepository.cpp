#include "TemperatureRepository.h"

TemperatureRepository::TemperatureRepository(int pin)
{
    this->pin = pin;
    oneWire = OneWire(pin);
    dallasTemperature = DallasTemperature(&oneWire);
}

void TemperatureRepository::init()
{
    dallasTemperature.begin();
}

float TemperatureRepository::measureTemperature()
{
    dallasTemperature.requestTemperatures();
    return dallasTemperature.getTempCByIndex(0);
}