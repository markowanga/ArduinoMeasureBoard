# ifndef MEASUREMENT
#  define MEASUREMENT
#include <RTClib.h>

class Measurement {

  private:
    DateTime dateTime;
    int counter;
    float distanceInMm;
    int light;
    float temperatureInCelcius;

  public:

    Measurement(DateTime dateTime, int counter, float distanceInMm, int light, float temperatureInCelcius);

    int getCounter();

    float getDistanceInMm();

    int getLight();

    float getTemperatureInCelcius();

};

# endif