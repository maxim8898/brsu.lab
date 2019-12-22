#include "SharpIR.h"
#include <Arduino.h>
#include <Servo.h>
#include "sensors.h"
#include "config.h"

byte Sensors::L;
byte Sensors::R;
byte Sensors::median[3][2] = {0};

SharpIR SharpL(LEFT,20150);
SharpIR SharpR(RIGHT,20150);


void Sensors::recalculation(){  
//  R = constrain(medianFilter(SharpR.distance(),0), 15, 120);
//  L = constrain(medianFilter(SharpL.distance(),1), 15, 120); 
  R = SharpR.distance();
  L = SharpL.distance();  
}

byte Sensors::medianFilter(byte currentValue, byte sensNum){
  for(byte i = 1; i < 3; i++){
    median[i-1][sensNum] = median[i][sensNum];
  }
  median[2][sensNum] = currentValue;
  byte maxVal = 0; byte minVal = 0;
  for(byte i=1; i<3; i++){
    if(median[i][sensNum] < median[minVal][sensNum]) minVal = i;
    if(median[i][sensNum] > median[maxVal][sensNum]) maxVal = i;
  }
  for(byte i=0; i<3; i++){
    if(i!=maxVal && i!=minVal)
    return median[i][sensNum];
  } 
}
