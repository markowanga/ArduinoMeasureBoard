#include <Arduino.h>
#include <JC_Button.h>

#include "Measurement.h"

#include "SdCardRepository.h"
#include "TemperatureRepository.h"
#include "DistanceRepository.h"
#include "LightRepository.h"
#include "WireClock.h"

#include <LiquidCrystal.h>
#include "ScreenContentManager.h"

#include "ProjectUtils.h"


int SD_CS_PIN = 10;
int TEMPERATURE_PIN = 19;
int DISTANCE_TRIGGER_PIN = 20;
int DISTANCE_ECHO_PIN = 21;
int LIGHT_PIN = A0;
int BUTTON_LEFT_PIN = 1;
int BUTTON_RIGHT_PIN = 0;
int LCD_RS = 4;
int LCD_E = 5;
int LCD_D4 = 6;
int LCD_D5 = 7;
int LCD_D6 = 8;
int LCD_D7 = 9;
String EXPORT_FILENAME = "measure.csv";

LiquidCrystal *lcd = new LiquidCrystal(LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

TemperatureRepository temperatureRepository = TemperatureRepository(TEMPERATURE_PIN);
SdCardRepository sdCardRepository = SdCardRepository(SD_CS_PIN);
DistanceRepository distanceRepository = DistanceRepository(DISTANCE_TRIGGER_PIN, DISTANCE_ECHO_PIN);
LightRepository lightRepository = LightRepository(LIGHT_PIN);
Button leftButton = Button(BUTTON_LEFT_PIN);
Button rightButton = Button(BUTTON_RIGHT_PIN);
WireClock wireClock;
int counter;

ScreenContentManager screenContentManager = ScreenContentManager(lcd);

void setup()
{
  delay(5000);
  Serial.begin(9600);
  lcd->begin(16, 2);
  sdCardRepository.init();
  sdCardRepository.prepareMeasuresFile(EXPORT_FILENAME);
  temperatureRepository.init();
  distanceRepository.init();
  lightRepository.init();
  leftButton.begin();
  rightButton.begin();
  wireClock.begin();
  counter = 0;
}

void updateMeasures()
{
  // int counter, int distanceInMm, int light, float temperatureInCelcius
  Measurement measurement = Measurement(
      wireClock.getCurrentDate(),
      counter++, 
      distanceRepository.measureDistance(),
      lightRepository.measureLight(),
      temperatureRepository.measureTemperature()
      );

  sdCardRepository.exportMeasurement(measurement, EXPORT_FILENAME);
  screenContentManager.updateScreenView(measurement);
}

void updateScreenPosition()
{
  leftButton.read();
  if (leftButton.wasPressed())
  {
    screenContentManager.decrementPosition();
  }
  rightButton.read();
  if (rightButton.wasPressed())
  {
    screenContentManager.incrementPosition();
  }
}

int i = 0;
void loop()
{
  updateMeasures();
  updateScreenPosition();
}