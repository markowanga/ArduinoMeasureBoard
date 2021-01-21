#include <Arduino.h>
#include <JC_Button.h>
// #include "measurement.h"
// #include "SdCardRepository.h"
#include "TemperatureRepository.h"
#include "DistanceRepository.h"
#include "LightRepository.h"
// #include "ScreenContentModel.h"
#include "WireClock.h"
// #include <LiquidCrystal.h>
#include "ProjectUtils.h"


int SD_CS_PIN = 4;
int TEMPERATURE_PIN = 19;
int DISTANCE_TRIGGER_PIN = 20;
int DISTANCE_ECHO_PIN = 21;
int LIGHT_PIN = A0;
int BUTTON_LEFT_PIN = 1;
int BUTTON_RIGHT_PIN = 0;
String EXPORT_FILENAME = "measures.csv";

// LiquidCrystal lcd(9, 8, 5, 4, 3, 2);

TemperatureRepository temperatureRepository = TemperatureRepository(TEMPERATURE_PIN);
// SdCardRepository sdCardRepository = SdCardRepository(SD_CS_PIN);
DistanceRepository distanceRepository = DistanceRepository(DISTANCE_TRIGGER_PIN, DISTANCE_ECHO_PIN);
LightRepository lightRepository = LightRepository(LIGHT_PIN);
Button leftButton = Button(BUTTON_LEFT_PIN);
Button rightButton = Button(BUTTON_RIGHT_PIN);
WireClock wireClock;
int counter;

// ScreenContentModel screenContentModel = ScreenContentModel();

void setup()
{
  // sdCardRepository.init();
  // sdCardRepository.prepareMeasuresFile(EXPORT_FILENAME);
  temperatureRepository.init();
  distanceRepository.init();
  lightRepository.init();
  leftButton.begin();
  // rightButton.begin();
  Serial.begin(9600);
  Serial.println("hello world");
  // lcd.begin(16, 2);
  // lcd.print("Elektro");
  // lcd.setCursor(6, 1);
  // lcd.print("Przewodnik");
  wireClock.begin();
}

// void updateCounterValue()
// {
//   incrementButton.read();
//   if (incrementButton.wasPressed())
//   {
//     counter++;
//   }
//   decrementButton.read();
//   if (decrementButton.wasPressed())
//   {
//     counter--;
//   }
// }

// void updateMeasures()
// {
//   // int counter, int distanceInMm, int light, float temperatureInCelcius
//   updateCounterValue();
//   Measurement measurement = Measurement(
//       wireClock.getCurrentDate(),
//       counter,
//       distanceRepository.measureDistance(),
//       lightRepository.measureDistance(),
//       temperatureRepository.measureTemperature());
//   sdCardRepository.exportMeasurement(measurement, millis(), EXPORT_FILENAME);
//   screenContentModel.updateScreenView(measurement);
// }

// void updateScreenPosition()
// {
//   downButton.read();
//   if (downButton.wasPressed())
//   {
//     screenContentModel.decrementPosition();
//   }
//   upButton.read();
//   if (upButton.wasPressed())
//   {
//     screenContentModel.incrementPosition();
//   }
// }

int i = 0;
void loop()
{
  Serial.println("Iteration: " + String(i++));
  delay(1000);
  auto dateTime = wireClock.getCurrentDate();
  // Serial.println("Time: " + ProjectUtils::dateTimeToString(dateTime));
  // Serial.println("Light: " + String(lightRepository.measureLight()));
  // Serial.println("Distance: " + String(distanceRepository.measureDistance()));
  // Serial.println("Temp: " + String(temperatureRepository.measureTemperature()));
  Serial.println("Right button: " + String(digitalRead(0)));
  Serial.println("Left button: " + String(leftButton.isPressed()));

  // updateMeasures();
  // updateScreenPosition();
}