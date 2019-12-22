/**
 * BrSU lab team
 */

// {"type": "set", "angle": 45, "speed": 1560};

#include "Arduino.h"
#include <Servo.h>
#include "motor.h"
#include "servos.h"
#include "sensors.h"
#include "digitalSensors.h"
#include <ArduinoJson.h>

String input = "";
String output = "";
int speed = 0;
short angle = 0;

void setup() {
  Motor::init();
  Servos::init();
  DigitalSensors::init();
  Serial.begin(9600);
  Motor::setSpeed(1540);
  Servos::setAngle(0);
}

void loop() {
  DigitalSensors::recalculation();
  Sensors::recalculation();
  receiveData();
  sendData();
  delay(20);
}

void sendData() {
  StaticJsonDocument<200> doc;
  doc["l45"] = DigitalSensors::L;
  doc["l0"] = Sensors::L;
  doc["r0"] = Sensors::R;
  doc["r45"] = DigitalSensors::R;
  doc["speed"] = speed;
  doc["angle"] = angle;  
  doc["time"] = millis();
  serializeJson(doc, Serial);
  Serial.println(";");
}

void receiveData() {
  int b = Serial.read();
  while (b != -1) {
    char c = b;
    input += c;
    b = Serial.read();
  }
  
  String package;
  Serial.println(input.length());
  for (int i = 0; i < input.length(); i++) {
    if (input[i] == ';') {
      deserializeAndExecute(package);
      package = "";
    } else {
      package += input[i];
    }
  }
  input = package;
}

void deserializeAndExecute(String value) {
  StaticJsonDocument<200> doc;
  if (deserializeJson(doc, value)) {
    return;
  }
  if (doc["type"] == "set") {
    executeCommand(doc);
  }
}

void executeCommand(StaticJsonDocument<200> doc) {
  if (doc.containsKey("angle")) {
    angle = doc["angle"];
    Servos::setAngle(angle);
  }
  if (doc.containsKey("speed")) {
    speed = doc["speed"];
    Motor::setSpeed(speed);
  }
}
