// #include "RTClib.h"
#include <Wire.h> // must be included here so that Arduino library object file references work
#include <RtcDS3231.h>

class WireClock
{
public:
    RtcDateTime getCurrentDate();
    void begin();
    WireClock();

private:
    RtcDS3231<TwoWire> *rtc;
};
