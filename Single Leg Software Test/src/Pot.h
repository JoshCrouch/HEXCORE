/*
    Handles inputs from potentiometers
*/

#include <Arduino.h>
#include <IK.h>

#ifndef Pot
#define Pot

#define PotPin1 A6
#define PotPin2 A5
#define PotPin3 A4

struct PotPositions{
    int Pot1;
    int Pot2;
    int Pot3;
};

void initialisePot();

PotPositions getPotPositions();

Position getLegPositionFromPot(Position LegPos);

void printPotPositions(PotPositions Pos);

#endif