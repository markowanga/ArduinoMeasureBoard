#include "SdCardRepository.h"

String SdCardRepository::getCsvMeasurementRowString(Measurement measure, long currentMillis)
{
    return String(currentMillis) + ";" + String(measure.getCounter()) + ";" + String(measure.getDistanceInMm()) + ";" + String(measure.getLight()) + ";" + String(measure.getTemperatureInCelcius());
}

bool SdCardRepository::writeLineToFile(String text_line, String filename)
{
    File myFile = SD.open(filename, FILE_WRITE);

    if (myFile)
    {
        Serial.print("Start writing to " + filename + "file");
        myFile.println(text_line + "\n");
        myFile.close();
        Serial.print("Finish writing to " + filename + "file");
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
    if (!SD.exists(filename))
    {
        return writeLineToFile(MEASURES_HEADER, filename);
    }
    return true;
}

bool SdCardRepository::exportMeasurement(Measurement measure, long currentMillis, String filename)
{
    return writeLineToFile(getCsvMeasurementRowString(measure, currentMillis), filename);
}

bool SdCardRepository::haveToSaveUpdatedMeasure()
{
    return lastSaveTime / updateSdPeriodMs < millis() / updateSdPeriodMs;
}