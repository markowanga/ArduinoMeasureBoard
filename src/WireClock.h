// #include "RTClib.h"
#include <Wire.h> // must be included here so that Arduino library object file references work
// #include <RtcDS3231.h>
#include <RTClib.h>

class WireClock
{
public:
    DateTime getCurrentDate();
    // RtcDateTime getCurrentDate();
    void begin();
    WireClock();

private:
    // RtcDS3231<TwoWire> *rtc;
    RTC_DS3231 rtc;
};
