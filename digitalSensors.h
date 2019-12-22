#include <Arduino.h>
#include <Servo.h>

class DigitalSensors{
  public:
    static byte L;
    static byte R;
    static void recalculation();
    static void init();
};
