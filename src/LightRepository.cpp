#include "LightRepository.h"

LightRepository::LightRepository(int pin)
{
    this->pin = pin;
}

void LightRepository::init()
{
    pinMode(pin, INPUT);
}

float LightRepository::measureLight()
{
    return analogRead(pin) / 1024.f;
}
