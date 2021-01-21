#include <Arduino.h>

class LightRepository
{
public:
    LightRepository(int pin);

    void init();

    float measureLight();

private:
    int pin;
};