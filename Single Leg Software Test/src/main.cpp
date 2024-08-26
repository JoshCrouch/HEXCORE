#include <Arduino.h>

#include <IK.h>
#include <Leg.h>
#include <Pot.h>

void setup() {
    Serial.begin(9600);

    initialisePot();
    initialiseLeg();
}

Position LegPosition = {0,0,0};

int index = 0;
void loop() {
    LegPosition = getLegPositionFromPot(LegPosition);
    setPosition(LegPosition);
    delay(1000);
    Serial.print("\n\n");
}