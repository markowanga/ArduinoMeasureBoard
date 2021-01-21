#include "SdCardRepository.h"

String SdCardRepository::getCsvMeasurementRowString(Measurement measure)
{
    String dateTime = ProjectUtils::dateTimeToString(measure.getMeasureDateTime());
    String counter = String(measure.getCounter());
    String distance = String(measure.getDistanceInMm());
    String light = String(measure.getLight());
    String temperature = String(measure.getTemperatureInCelcius());
    return dateTime + String(";") + counter + String(";") + distance + String(";") + light + String(";") + temperature;
}

bool SdCardRepository::writeLineToFile(String text_line, String filename)
{
    File myFile = SD.open(filename.c_str(), FILE_WRITE);
    if (myFile)
    {
        Serial.println("Start writing to " + filename + " file");
        myFile.println(text_line);
        myFile.close();
        Serial.println("Finish writing to " + filename + " file");
        lastSaveTime = millis();
        return true;
    }
    else
    {
        Serial.println("Error opening " + filename);
        return false;
    }
}

SdCardRepository::SdCardRepository(int csPin)
{
    this->csPin = csPin;
    this->lastSaveTime = 0;
}

bool SdCardRepository::init()
{
    Serial.println("Initialization start");
    if (!SD.begin(csPin))
    {
        Serial.println("Initialization failed");
        return false;
    }
    else
    {
        Serial.println("Initialization succeed");
        return true;
    }
}

bool SdCardRepository::prepareMeasuresFile(String filename)
{
    // if (!SD.exists(filename.c_str()))
    // {
    //     return writeLineToFile(MEASURES_HEADER, filename);
    // }
    return true;
}

bool SdCardRepository::exportMeasurement(Measurement measure, String filename)
{
    return writeLineToFile(getCsvMeasurementRowString(measure), filename);
}

bool SdCardRepository::haveToSaveUpdatedMeasure()
{
    return ((unsigned long)lastSaveTime / (unsigned long)updateSdPeriodMs) < (millis() / (unsigned long)updateSdPeriodMs);
}
