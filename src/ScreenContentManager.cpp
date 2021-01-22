#include "ScreenContentManager.h"

ScreenContentManager::ScreenContentManager(LiquidCrystal *lcd)
{
    this->lcd = lcd;
    currentPosition = 0;
    for (int i = 0; i < 7; i++)
    {
        lines[i] = "";
    }
    lines[7] = " Designed by:";
    lines[8] = "   JACEK WATROBA";
    lines[9] = " for WSB Cieszyn";
}

void ScreenContentManager::updateScreenView(Measurement measurement)
{
    lines[0] = ProjectUtils::dateToString(measurement.getMeasureDateTime());
    lines[1] = ProjectUtils::timeToString(measurement.getMeasureDateTime());
    lines[2] = "Dist: " + String(measurement.getDistanceInMm()) + "mm";
    lines[3] = "Light: " + String(measurement.getLight()) + "%";
    lines[4] = "Temp: " + String(measurement.getTemperatureInCelcius()) + " " + (char)0xDF + "C";
    lines[5] = "Count: " + String(measurement.getCounter()) + " taps";
    updateScreen();
}

void ScreenContentManager::incrementPosition()
{
    currentPosition++;
    if (currentPosition == SCREEN_LINES_COUNT)
    {
        currentPosition = 0;
    }
    updateScreen();
}

void ScreenContentManager::decrementPosition()
{
    currentPosition--;
    if (currentPosition == -1)
    {
        currentPosition = SCREEN_LINES_COUNT - 1;
    }
    updateScreen();
}

void ScreenContentManager::updateScreen()
{
    String line1 = ProjectUtils::fillSpacesToLength(lines[currentPosition], 16);
    String line2 = ProjectUtils::fillSpacesToLength(lines[(currentPosition + 1) % (SCREEN_LINES_COUNT)], 16);
    showLines(line1, line2);
}

void ScreenContentManager::showLines(String line1, String line2)
{
    lcd->setCursor(0, 0);
    lcd->print(ProjectUtils::fillSpacesToLength(line1, 16));
    lcd->setCursor(0, 1);
    lcd->print(ProjectUtils::fillSpacesToLength(line2, 16));
}
