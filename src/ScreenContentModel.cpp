#include "ScreenContentModel.h"

ScreenContentModel::ScreenContentModel()
{
    currentPosition = 0;
    for (int i = 0; i < 5; i++)
    {
        lines[i] = "";
    }
    lines[5] = "  Designed by:";
    lines[6] = "   JACEK WĄTROBA";
    lines[7] = "";
}

void ScreenContentModel::updateScreenView(Measurement measurement)
{
    lines[0] = "Distance: " + String(measurement.getDistanceInMm()) + "mm";
    lines[1] = "Light: " + String(measurement.getLight()) + "%";
    lines[2] = "Temp: " + String(measurement.getTemperatureInCelcius()) + "°C";
    lines[3] = "Counter: " + String(measurement.getCounter()) + " taps";
    updateScreen();
}

void ScreenContentModel::incrementPosition()
{
    currentPosition++;
    if (currentPosition == 4)
    {
        currentPosition = 0;
    }
    updateScreen();
}

void ScreenContentModel::decrementPosition()
{
    currentPosition--;
    if (currentPosition == -1)
    {
        currentPosition = 3;
    }
    updateScreen();
}

void ScreenContentModel::updateScreen()
{
    showLines(lines[currentPosition], lines[(currentPosition + 1) % 4]);
}

void ScreenContentModel::showLines(String line1, String line2)
{
    // TODO
}