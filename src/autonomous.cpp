#include "main.h"
using namespace pros::literals;
Motor left_mtrAuto(3);
Motor forward_left_mtrAuto(4);
Motor right_mtrAuto(8);
Motor forward_right_mtrAuto(1);
Motor craneAuto(13);
Motor launcherAuto(6);
Motor launcher2Auto(7);
Motor intakeAuto(15);

void flip(int val) {
  // 1 represents on, crane is up.
  if (val == 1) {
    craneAuto.move_voltage(12000);
    delay(200);
    craneAuto.move_voltage(0);
  }
  // flip cap value
  if (val == 2) {
    craneAuto.move_voltage(12000);
    delay(350);
    craneAuto.move_voltage(0);
  }
  // 0 represents off, crane is down.
  if (val == 0) {
    craneAuto.move_voltage(-12000);
    delay(70);
    craneAuto.move_voltage(0);
  }
}
// Move the motors.
void motors(int left, int forLeft, int right, int forRight, int velocityLeft, int velocityRight) {
  left_mtrAuto.move_relative(left, velocityLeft);
  forward_left_mtrAuto.move_relative(forLeft, velocityLeft);
  right_mtrAuto.move_relative(right, velocityRight);
  forward_right_mtrAuto.move_relative(forRight, velocityRight);
}

void rotate(float deg) {

}

void turn(float deg, float squares) {

}

void autonomous() {
  // 165 is about 180 degrees
  // 90 degrees is 95 degrees

  // 1 is skills time
  // Hit flag and move back
  if (red == true) {
    if (front == true) {

    }
  }
}
