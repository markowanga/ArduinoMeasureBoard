#include "ProjectUtils.h"

String ProjectUtils::zeroPad(String value, int size)
{
    String zeros = "";
    for (int i = 0; i < size - value.length(); i++)
    {
        zeros = zeros + "0";
    }
    return zeros + value;
}

String ProjectUtils::dateTimeToString(RtcDateTime dateTime)
{
    auto year =zeroPad(String(dateTime.Year()), 4); 
    auto month = zeroPad(String(dateTime.Month()), 2);
    auto day = zeroPad(String(dateTime.Day()), 2);
    auto hour = zeroPad(String(dateTime.Hour()), 2);
    auto minute = zeroPad(String(dateTime.Minute()), 2);
    auto second = zeroPad(String(dateTime.Second()), 2);
    return year + "." + month + "." + day + "T" + hour + ":" + minute + ":" + second;
}
