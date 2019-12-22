#include <Arduino.h>
#include <Servo.h>

class Sensors{
  public:
    static byte L;
    static byte R;
    static void recalculation();
  private:
    static byte median[3][2];
    static byte medianFilter(byte currentValue, byte sensNum);
    static byte averageElem(byte first, byte second, byte third);
};
