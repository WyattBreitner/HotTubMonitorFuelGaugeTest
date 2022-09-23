
#include "Adafruit_MAX1704X.h"

Adafruit_MAX17048 fuelGauge;

void setup() {
    Serial.begin(115200);

    Serial.println("Starting Fuel Gauge Test!");

    while(!fuelGauge.begin()) {
        Serial.println("I2C Fuel Gauge Begin Failed, check battery");
        delay(1000);
    }

    Serial.println();
    Serial.print("Chip ID: ");
    Serial.println(fuelGauge.getChipID(), HEX);
    Serial.println();
}


void loop() {
    Serial.print("Battery Voltage: "); Serial.print(fuelGauge.cellVoltage(), 3); Serial.println("V");
    Serial.print("Battery Percent: "); Serial.print(fuelGauge.cellPercent(), 1); Serial.println("%");
    Serial.println();

    delay(2000);
}