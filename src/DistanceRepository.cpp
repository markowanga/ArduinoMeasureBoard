#include "DistanceRepository.h"

DistanceRepository::DistanceRepository(int trigerPin, int echoPin)
{
    this->trigerPin = trigerPin;
    this->echoPin = echoPin;
}

void DistanceRepository::init()
{
    pinMode(trigerPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

float DistanceRepository::measureDistance()
{
    digitalWrite(trigerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigerPin, HIGH);
    delayMicroseconds(15);
    digitalWrite(trigerPin, LOW);
    digitalWrite(echoPin, HIGH);
    return (float)pulseIn(echoPin, HIGH) / 5.8;
}
