/*
    Handles all of the inverse kinematics calculations. For general use call
*/


#include <math.h>

#ifndef IK
#define IK

#define RadiansToDegrees (180 / PI)

const int FOOTLEN = 100;
const int TIBLEN = 75;
const int FEMLEN = 75;

struct Position {
    double x;
    double y;
    double z;
};

struct Angles {
    double hip;
    double knee;
    double ankle;
};

// Translates from Leg's positon to IK position
Position LegToIKTranslate(Position LegPos);

// Constrain the end position
Position ConstrainPosition(Position LegPos);

// Calculates the angles using IK's position and returns IK angles
Angles CalculateIK(Position IKPos);

// Translates IK angles to Servo Angles
Angles IKtoServo(Angles IKAngles);

// Uses other functions to transfer from LegCoords to IK, calculate angles
// and then translate to servo angles
Angles LegIKCalculation(Position LegPos);

// Function to print a set of angles in a clean manner
void printAngles(Angles Printed);

// Function to print a set of positions in a clean manner
void printPosition(Position Pos);


#endif