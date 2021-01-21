#include <Arduino.h>
#include <RtcDS3231.h>

class ProjectUtils {
public:
    static String dateTimeToString(RtcDateTime dateTime);
    static String zeroPad(String value, int size);
};