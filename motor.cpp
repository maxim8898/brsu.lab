#include <Arduino.h>
#include <Servo.h>
#include <math.h>
#include "config.h"
#include "motor.h"

Servo Motor::motor;

void Motor::init(){
  motor.attach(MOTOR_PIN, 544, 2400);
  motor.writeMicroseconds(SPEED_ZERO);
  delay(3000);
}

void Motor::setSpeed(int speed){
  motor.writeMicroseconds(speed);
}

void Motor::setSpeed(float speed){
  motor.writeMicroseconds(Motor::speedConverter(speed));
}

int Motor::speedConverter(float speed){
  return trunc(pow(speed,4)*0.1148 - pow(speed,3)*1.964 + pow(speed,2)*10.041 - speed*8.8379 + 1546.7); 
}
