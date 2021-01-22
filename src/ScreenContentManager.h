#include <Arduino.h>
#include "Measurement.h"
#include <LiquidCrystal.h>
#include "ProjectUtils.h"

#define SCREEN_LINES_COUNT 10


class ScreenContentManager
{
public:
    ScreenContentManager(LiquidCrystal *lcd);

    void updateScreenView(Measurement measurement);

    void incrementPosition();

    void decrementPosition();

private:
    LiquidCrystal *lcd;
    int currentPosition;
    String lines[SCREEN_LINES_COUNT];

    void updateScreen();

    void showLines(String line1, String line2);
};
