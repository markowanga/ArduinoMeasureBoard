#include <Arduino.h>
#include "Measurement.h"

class ScreenContentModel
{
public:
    ScreenContentModel();

    void updateScreenView(Measurement measurement);

    void incrementPosition();

    void decrementPosition();

private:
    int currentPosition;
    String lines[8];

    void updateScreen();

    void showLines(String line1, String line2);
};
