#include "main.h"
using namespace pros::literals;
Motor left_mtrAuto(3);
Motor forward_left_mtrAuto(4);
Motor right_mtrAuto(8);
Motor forward_right_mtrAuto(18);
Motor craneAuto(13);
Motor launcherAuto(6);
Motor launcher2Auto(7);
Motor intakeAuto(15);
int posLeft = 0;
int posForLeft = 0;
int posRight = 0;
int posForRight = 0;

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

  // calculating new positions
  posLeft = posLeft + left;
  posForLeft = posForLeft + forLeft;
  posRight = posRight + forRight;
  posForRight = posForRight + forRight;

  while (!((left_mtrAuto.get_position() < (posLeft + 5)) && (left_mtrAuto.get_position() > (posLeft - 5)))) {
    pros::delay(2);
  }

  while (!((forward_left_mtrAuto.get_position() < (posForLeft + 5)) && (forward_left_mtrAuto.get_position() > (posForLeft - 5)))) {
    pros::delay(2);
  }

  while (!((right_mtrAuto.get_position() < (posRight + 5)) && (right_mtrAuto.get_position() > (posRight - 5)))) {
    pros::delay(2);
  }

  while (!((forward_right_mtrAuto.get_position() < (posForRight + 5)) && (forward_right_mtrAuto.get_position() > (posForRight - 5)))) {
    pros::delay(2);
  }

  // gets position for the next use of this function
  posLeft = left_mtrAuto.get_position();
  posForLeft = forward_left_mtrAuto.get_position();
  posRight = right_mtrAuto.get_position();
  posForRight = forward_right_mtrAuto.get_position();
}

void rotate(float deg) {

}

void turn(float deg, float squares) {

}

void autonomous() {
  if (red == true) {
    if (front == true) {
      motors(1000, 1000, -1000, -1000, 1000, -1000);
      delay(20);
    }
  }
}
