#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensor(&oneWire);

float Celsius = 0;
float Fahrenheit = 0;

void setup() {
  sensor.begin();
  Serial.begin(9600);
}

void loop() {
  sensor.requestTemperatures();

  Celsius = sensor.getTempCByIndex(0);
  Fahrenheit = sensor.toFahrenheit(Celsius);

  Serial.print(Celsius);
  Serial.print(" C  ");
  Serial.print(Fahrenheit);
  Serial.println(" F");

  delay(1000);
}
