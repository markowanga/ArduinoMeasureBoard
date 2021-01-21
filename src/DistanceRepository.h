#include <Arduino.h>

class DistanceRepository
{
public:
    DistanceRepository(int trigerPin, int echoPin);

    void init();

    float measureDistance();

private:
    int trigerPin;
    int echoPin;
};
