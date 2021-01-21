#include "Measurement.h"
#include "ProjectUtils.h"
#include <Arduino.h>
#include <SPI.h>
#include <SD.h>

#define MEASURES_HEADER "milisecondsFromStart;counter;distance_in_mm;light;temperature"

class SdCardRepository
{
public:
    SdCardRepository(int csPin);

    bool init();

    bool prepareMeasuresFile(String filename);

    bool exportMeasurement(Measurement measure, String filename);

    bool haveToSaveUpdatedMeasure();

    bool writeLineToFile(String text_line, String filename);

private:
    int csPin;
    int lastSaveTime;
    const static int updateSdPeriodMs = 10000;

    String getCsvMeasurementRowString(Measurement measure);

};
