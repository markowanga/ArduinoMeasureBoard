#include "Measurement.h"

Measurement::Measurement(DateTime dateTime, int counter, float distanceInMm, float light, float temperatureInCelcius)
{
  this->dateTime = dateTime;
  this->counter = counter;
  this->distanceInMm = distanceInMm;
  this->light = light;
  this->temperatureInCelcius = temperatureInCelcius;
}

DateTime Measurement::getMeasureDateTime() {
  return dateTime;
}

int Measurement::getCounter()
{
  return counter;
}

float Measurement::getDistanceInMm()
{
  return distanceInMm;
}

float Measurement::getLight()
{
  return light;
}

float Measurement::getTemperatureInCelcius()
{
  return temperatureInCelcius;
}
