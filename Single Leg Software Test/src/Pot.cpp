#include <Pot.h>

PotPositions PotOffset = {504, 520, 512};

void initialisePot() {
    pinMode(PotPin1, INPUT); // Joystick X
    pinMode(PotPin2, INPUT); // Joystick Y
    pinMode(PotPin3, INPUT); // Orange Pot
}

PotPositions getPotPositions() {
    PotPositions Pos;
    Pos.Pot1 = analogRead(PotPin1);
    Pos.Pot2 = analogRead(PotPin2);
    Pos.Pot3 = analogRead(PotPin3);
    return Pos;
}

Position getLegPositionFromPot(Position LegPos) {
    PotPositions PotPos = getPotPositions();
    printPotPositions(PotPos);
    LegPos.x =  (PotPos.Pot3 - PotOffset.Pot3)/10;
    LegPos.y += (PotPos.Pot1 - PotOffset.Pot1)/100;
    LegPos.z += (PotPos.Pot2 - PotOffset.Pot2)/100;
    return ConstrainPosition(LegPos);
}

void printPotPositions(PotPositions Pos) {
    Serial.print("Pot1: "); Serial.print(Pos.Pot1);
    Serial.print("\tPot2: "); Serial.print(Pos.Pot2);
    Serial.print("\tPot3: "); Serial.println(Pos.Pot3);
}