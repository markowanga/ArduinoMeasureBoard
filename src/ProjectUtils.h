# ifndef PROJECT_UTILS__
#  define PROJECT_UTILS__

#include <Arduino.h>
// #include <RtcDS3231.h>
#include <RTClib.h>

class ProjectUtils {
public:
    // static String dateTimeToString(RtcDateTime dateTime);
    static String dateTimeToString(DateTime dateTime);
    static String zeroPad(String value, int size);
};

# endif