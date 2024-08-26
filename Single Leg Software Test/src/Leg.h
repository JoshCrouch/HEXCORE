/*
    Handles a Leg and related parts, makes use of IK to move to positions
*/

#include <Servo.h>
#include <IK.h>

#ifndef Leg
#define Leg

struct LegPins {
    int anklePin;
    int kneePin;
    int hipPin;
};

struct LegServos
{
    Servo ankle;
    Servo knee;
    Servo hip;
};

void initialiseLeg();

void setPosition(Position Pos);

#endif