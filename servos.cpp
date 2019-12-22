#include <Arduino.h>
#include <Servo.h>
#include "servos.h"

Servo Servos::servos;
short Servos::currentAngle;

void Servos::init(){
  servos.attach(9, 950, 2040);
  servos.write(90);
  currentAngle = 0;
}

void Servos::setAngle(short value){
  servos.write(90 + value); 
  currentAngle = value;
}

short Servos::getAngle(){
  return currentAngle;
}
