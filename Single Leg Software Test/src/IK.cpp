0.#include <IK.h>
#include <Arduino.h>

const Position LegZero = {0,(TIBLEN+FOOTLEN),0};
const Angles ServoOffset = {90,90,90}; // {Hip, Knee, Ankle} - Idk why it's backwards
const int TIB2 = pow(TIBLEN, 2); 
const int FOOT2 = pow(FOOTLEN, 2); 

Position LegToIKTranslate(Position LegPos) {
    Position IKPos;
    IKPos.x = LegZero.x + LegPos.x;
    IKPos.y = LegZero.y + LegPos.y;
    IKPos.z = LegZero.z + LegPos.z;
    return IKPos;
}

Position ConstrainPosition(Position LegPos) {
    Position constrained;
    constrained.x = constrain(LegPos.x, -50, 50);
    constrained.y = constrain(LegPos.y, -LegZero.y, 0);
    constrained.z = constrain(LegPos.z, -LegZero.y, 0);

    return constrained;
}

Angles CalculateIK(Position IKPosition) {
    Angles IKAngles;

    double hip = atan(IKPosition.x / IKPosition.y) * RadiansToDegrees;
    IKAngles.hip = hip;

    double H = sqrt(pow(IKPosition.y, 2) + pow(IKPosition.x, 2)) - FEMLEN;
    double H2 = pow(H, 2);

    double L = sqrt(H2 + pow(IKPosition.z, 2));
    double L2 = pow(L, 2);

    // Calculate Ankle Angle
    double ankle = acos( (TIB2+FOOT2-L2)  /  (2*TIBLEN*FOOTLEN) ) * RadiansToDegrees;
    IKAngles.ankle = ankle;


    // Finding Knee Angle
    double beta = acos( (L2+TIB2-FOOT2)  /  (2*L*TIBLEN) ) * RadiansToDegrees;
    double alpha = atan( IKPosition.z / H ) * RadiansToDegrees;
    double knee = beta+alpha;
    IKAngles.knee = knee;

    Serial.print("L: "); Serial.print(L);
    Serial.print("\tBetacos: "); Serial.print((L2+TIB2-FOOT2)  /  (2*L*TIBLEN));
    Serial.print("\tBeta: "); Serial.print(beta);
    Serial.print("\tAlpha: "); Serial.println(alpha);

    return IKAngles;
}

Angles IKtoServo(Angles IKAngles) {
    Angles ServoAngles;
    ServoAngles.ankle = IKAngles.ankle - ServoOffset.ankle;
    ServoAngles.knee = ServoOffset.knee - IKAngles.knee;
    ServoAngles.hip = IKAngles.hip + ServoOffset.hip;
    return ServoAngles;
}

Angles LegIKCalculation(Position LegPos) {
    Position IKPos = LegToIKTranslate(LegPos);
    Angles IKAngles = CalculateIK(IKPos);
    return IKtoServo(IKAngles);
}

void printAngles(Angles Ang) {
    Serial.print("Ankle: "); Serial.print(Ang.ankle);
    Serial.print("\tKnee: "); Serial.print(Ang.knee);
    Serial.print("\tHip: "); Serial.println(Ang.hip);
}

void printPosition(Position Pos) {
    Serial.print("x: "); Serial.print(Pos.x);
    Serial.print("\ty: "); Serial.print(Pos.y);
    Serial.print("\tz: "); Serial.println(Pos.z);
}