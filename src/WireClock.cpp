#include "WireClock.h"

WireClock::WireClock()
{
    rtc = new RtcDS3231<TwoWire>(Wire);
}

RtcDateTime WireClock::getCurrentDate()
{
    return rtc->GetDateTime();
}

void WireClock::begin()
{
    rtc->Begin();

    RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);

    if (!rtc->IsDateTimeValid())
    {
        if (rtc->LastError() != 0)
        {
            // we have a communications error
            // see https://www.arduino.cc/en/Reference/WireEndTransmission for
            // what the number means
            Serial.print("RTC communications error = ");
            Serial.println(rtc->LastError());
        }
        else
        {
            // Common Causes:
            //    1) first time you ran and the device wasn't running yet
            //    2) the battery on the device is low or even missing

            Serial.println("RTC lost confidence in the DateTime!");

            // following line sets the RTC to the date & time this sketch was compiled
            // it will also reset the valid flag internally unless the Rtc device is
            // having an issue

            rtc->SetDateTime(compiled);
        }
    }

    if (!rtc->GetIsRunning())
    {
        Serial.println("RTC was not actively running, starting now");
        rtc->SetIsRunning(true);
    }

    RtcDateTime now = rtc->GetDateTime();
    if (now < compiled)
    {
        Serial.println("RTC is older than compile time!  (Updating DateTime)");
        rtc->SetDateTime(compiled);
    }
    else if (now > compiled)
    {
        Serial.println("RTC is newer than compile time. (this is expected)");
    }
    else if (now == compiled)
    {
        Serial.println("RTC is the same as compile time! (not expected but all is fine)");
    }

    // never assume the Rtc was last configured by you, so
    // just clear them to your needed state
    rtc->Enable32kHzPin(false);
    rtc->SetSquareWavePin(DS3231SquareWavePin_ModeNone);
}

String printDateTime(const RtcDateTime &dt)
{
    return String(dt.Year()) + "." + String(dt.Month()) + "." + String(dt.Day()) + "T" + String(dt.Hour()) + ":" + String(dt.Minute()) + ":" + String(dt.Second());
}
