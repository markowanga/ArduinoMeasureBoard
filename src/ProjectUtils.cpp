#include "ProjectUtils.h"

String ProjectUtils::zeroPad(String value, int size)
{
    String zeros = "";
    for (int i = 0; i < (int)size - (int)value.length(); i++)
    {
        zeros = zeros + "0";
    }
    return zeros + value;
}

String ProjectUtils::dateToString(DateTime dateTime)
{
    auto year = zeroPad(String(dateTime.year()), 4);
    auto month = zeroPad(String(dateTime.month()), 2);
    auto day = zeroPad(String(dateTime.day()), 2);
    return year + "." + month + "." + day;
}

String ProjectUtils::timeToString(DateTime dateTime)
{
    auto hour = zeroPad(String(dateTime.hour()), 2);
    auto minute = zeroPad(String(dateTime.minute()), 2);
    auto second = zeroPad(String(dateTime.second()), 2);
    return hour + ":" + minute + ":" + second;
}

String ProjectUtils::dateTimeToString(DateTime dateTime)
{
    return dateToString(dateTime) + "T" + timeToString(dateTime);
}

String ProjectUtils::fillSpacesToLength(String value, int length)
{
    String filledValue = value;
    while (filledValue.length() < length)
    {
        filledValue = filledValue + " ";
    }
    return filledValue.substring(0, length);
} 