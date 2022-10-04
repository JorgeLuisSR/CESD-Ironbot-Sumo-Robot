#include <AFMotor.h>
#include <Servo.h>
#include <SoftwareSerial.h>

//Declares the bluetooth Receive pin an Transmision pin (Board, not component)
SoftwareSerial BTP(0, 1);
//Declares & asing the motors like Left Front-Back & Right Front-Back
AF_DCMotor LF(1);
AF_DCMotor LB(2);
AF_DCMotor RF(3);
AF_DCMotor RB(4);

Servo LS;
Servo RS;

//Declares Velocities for Rotation and going ForWarD/BackWarD
const int VRot = 100;
const int VFWD = 200;
const int VBWD = 150;

//Declaares the Servoss Angle to move the shovel
const int SAng = 90;

char Data = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("On");
  BTP.begin(38400);
  RS.attach(9);
  LS.attach(10);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (BTP.available()) {
    Data = BTP.read();
    switch (Data) {
      case 'F':
        fwd();
        break;
      case 'B':
        bwd();
        break;
      case 'R':
        rot(true);
        break;
      case 'L':
        rot(false);
        break;
      case 'A':
        atk();
        break;
      default:
        stop();
        break;
    }
  }
}

void rot(bool isR) {
  LF.setSpeed(VRot);
  LB.setSpeed(VRot);
  RF.setSpeed(VRot);
  RB.setSpeed(VRot);
  if (isR) {
    LF.run(FORWARD);
    LB.run(FORWARD);
    RF.run(BACKWARD);
    RB.run(BACKWARD);
  } else {
    RF.run(FORWARD);
    RB.run(FORWARD);
    LF.run(BACKWARD);
    LB.run(BACKWARD);
  }
}

void fwd() {
  LF.setSpeed(VFWD);
  LB.setSpeed(VFWD);
  RF.setSpeed(VFWD);
  RB.setSpeed(VFWD);
  LF.run(FORWARD);
  LB.run(FORWARD);
  RF.run(FORWARD);
  RB.run(FORWARD);
}

void bwd() {
  LF.setSpeed(VBWD);
  LB.setSpeed(VBWD);
  RF.setSpeed(VBWD);
  RB.setSpeed(VBWD);
  LF.run(BACKWARD);
  LB.run(BACKWARD);
  RF.run(BACKWARD);
  RB.run(BACKWARD);
}

void stop() {
  LF.run(RELEASE);
  LB.run(RELEASE);
  RF.run(RELEASE);
  RB.run(RELEASE);
}

void atk() {
  for (int i = 0; i < SAng; i = i + 2) {
    RS.write(90 - i);
    LS.write(90 + i);
    delay(3);
  }
}
