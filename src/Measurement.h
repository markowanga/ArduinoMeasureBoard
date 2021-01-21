# ifndef MEASUREMENT__
#  define MEASUREMENT__
// #include "RtcDateTime.h"
#include <RTClib.h>

class Measurement {

  private:
    DateTime dateTime;
    int counter;
    float distanceInMm;
    float light;
    float temperatureInCelcius;

  public:

    Measurement(DateTime dateTime, int counter, float distanceInMm, float light, float temperatureInCelcius);

    DateTime getMeasureDateTime();

    int getCounter();

    float getDistanceInMm();

    float getLight();

    float getTemperatureInCelcius();

};

# endif