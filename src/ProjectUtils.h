# ifndef PROJECT_UTILS__
#  define PROJECT_UTILS__

#include <Arduino.h>
#include <RTClib.h>

class ProjectUtils {
public:
    static String dateToString(DateTime dateTime);
    static String timeToString(DateTime dateTime);
    static String dateTimeToString(DateTime dateTime);
    static String zeroPad(String value, int size);
    static String fillSpacesToLength(String value, int length);
};

# endif