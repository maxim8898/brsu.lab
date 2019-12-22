#include <Servo.h>
#include <Arduino.h>

class Servos{
  public:
  static short currentAngle;
  static Servo servos;
  static void init();
  static void setAngle(short value);
  static short getAngle();  
};
