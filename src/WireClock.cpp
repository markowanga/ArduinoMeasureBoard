#include "WireClock.h"

WireClock::WireClock()
{
    // rtc = new RtcDS3231<TwoWire>(Wire);
}

// RtcDateTime WireClock::getCurrentDate()
// {
//     return rtc->GetDateTime();
// }

DateTime WireClock::getCurrentDate()
{
    return rtc.now();
}

// void WireClock::begin()
// {
//     rtc->Begin();

//     RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);

//     if (!rtc->IsDateTimeValid())
//     {
//         if (rtc->LastError() != 0)
//         {
//             // we have a communications error
//             // see https://www.arduino.cc/en/Reference/WireEndTransmission for
//             // what the number means
//             Serial.print("RTC communications error = ");
//             Serial.println(rtc->LastError());
//         }
//         else
//         {
//             // Common Causes:
//             //    1) first time you ran and the device wasn't running yet
//             //    2) the battery on the device is low or even missing

//             Serial.println("RTC lost confidence in the DateTime!");

//             // following line sets the RTC to the date & time this sketch was compiled
//             // it will also reset the valid flag internally unless the Rtc device is
//             // having an issue

//             rtc->SetDateTime(compiled);
//         }
//     }

//     if (!rtc->GetIsRunning())
//     {
//         Serial.println("RTC was not actively running, starting now");
//         rtc->SetIsRunning(true);
//     }

//     RtcDateTime now = rtc->GetDateTime();
//     if (now < compiled)
//     {
//         Serial.println("RTC is older than compile time!  (Updating DateTime)");
//         rtc->SetDateTime(compiled);
//     }
//     else if (now > compiled)
//     {
//         Serial.println("RTC is newer than compile time. (this is expected)");
//     }
//     else if (now == compiled)
//     {
//         Serial.println("RTC is the same as compile time! (not expected but all is fine)");
//     }

//     // never assume the Rtc was last configured by you, so
//     // just clear them to your needed state
//     rtc->Enable32kHzPin(false);
//     rtc->SetSquareWavePin(DS3231SquareWavePin_ModeNone);
// }

void WireClock::begin()
{
    if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    abort();
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, let's set the time!");
    // When time needs to be set on a new device, or after a power loss, the
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
}