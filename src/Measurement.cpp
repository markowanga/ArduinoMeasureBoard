#include "Measurement.h"

Measurement::Measurement(DateTime datetime, int counter, float distanceInMm, int light, float temperatureInCelcius)
{
  this->dateTime = dateTime;
  this->counter = counter;
  this->distanceInMm = distanceInMm;
  this->light = light;
  this->temperatureInCelcius = temperatureInCelcius;
}

int Measurement::getCounter()
{
  return counter;
}

float Measurement::getDistanceInMm()
{
  return distanceInMm;
}

int Measurement::getLight()
{
  return light;
}

float Measurement::getTemperatureInCelcius()
{
  return temperatureInCelcius;
}
