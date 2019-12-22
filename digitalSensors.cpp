#include <Arduino.h>
#include <Wire.h>
#include <VL53L0X.h>
#include "digitalSensors.h"

byte DigitalSensors::L;
byte DigitalSensors::R;
VL53L0X sensor1;
VL53L0X sensor2;

void DigitalSensors::init(){
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);
  digitalWrite(3, LOW);
  digitalWrite(5, LOW);

  delay(500);
  Wire.begin();

  digitalWrite(3, HIGH);
  delay(150);
  sensor1.init(true);
 
  delay(100);
  sensor1.setAddress((uint8_t)22);
  
  digitalWrite(5, HIGH);
  delay(150);
  sensor2.init(true);
  delay(100);
  sensor2.setAddress((uint8_t)25);
}

void DigitalSensors::recalculation(){
  R = constrain(sensor1.readRangeSingleMillimeters(), 0, 600) / 10;
  L = constrain(sensor2.readRangeSingleMillimeters(), 0, 600) / 10;  
}
