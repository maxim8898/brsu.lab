#include <Servo.h>
#include <Arduino.h>

class Motor{
public:
  static void init();
  static void setSpeed(int speed);      //   impulce
  static void setSpeed(float speed);    //   km/h
  static int speedConverter(float speed);//  km/h  to  impulce
  static Servo motor;
};
