/*
 * Made compatible for Sparkcore
 * Author: Geert Wille
*/
/**************************************************************************
 *                                                                         *
 * MAX1704* Driver for Arduino                                             *
 *                                                                         *
 * Matthew Newberry                                                        *
 * mattnewberry@me.com                                                     *
 *                                                                         *
 ***************************************************************************
 *                                                                         *
 * This program is free software; you can redistribute it and/or modify    *
 * it under the terms of the GNU License.                                  *
 * This program is distributed in the hope that it will be useful,         *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of          *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           *
 * GNU License V2 for more details.                                        *
 *                                                                         *
 ***************************************************************************/

#include "MAX1704.h"

MAX1704 fuelGauge;

char batteryStr[20];

void setup() {
    Spark.variable("battInfo", &batteryStr, STRING);

    Wire.begin();
    Serial.begin(9600);

    Serial.println("Starting up...");
    delay(1000);
    fuelGauge.reset();
    fuelGauge.quickStart();
    fuelGauge.showConfig();
    delay(1000);
}

void loop() {
    delay(1000);
    float charge = fuelGauge.stateOfCharge();
    sprintf(batteryStr, "%.2f", charge);
    Serial.println(batteryStr);
    delay(1000);
}