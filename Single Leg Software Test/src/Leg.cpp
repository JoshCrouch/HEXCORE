#include <Leg.h>

#define ANKLEPIN 2
#define KNEEPIN 3
#define HIPPIN 4

LegPins Pins = {ANKLEPIN, KNEEPIN, HIPPIN};

Servo ankle;
Servo knee;
Servo hip;

LegServos Servos = {ankle, knee, hip};


void initialiseLeg(){
    Servos.ankle.attach(Pins.anklePin);
    Servos.knee.attach(Pins.kneePin);
    Servos.hip.attach(Pins.hipPin);
}

void setPosition(Position Pos){
    Angles ServoAngles = LegIKCalculation(Pos);
    printPosition(Pos);
    printAngles(ServoAngles);
    Servos.ankle.write(ServoAngles.ankle);
    Servos.knee.write(ServoAngles.knee);
    Servos.hip.write(ServoAngles.hip);
}