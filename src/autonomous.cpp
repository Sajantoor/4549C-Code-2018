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

void calculatePosition() {
  posLeft = left_mtrAuto.get_position();
  posForLeft = forward_left_mtrAuto.get_position();
  posRight = right_mtrAuto.get_position();
  posForRight = forward_right_mtrAuto.get_position();
}

// Move the motors.
void motors(int left, int forLeft, int right, int forRight, int velocityLeft, int velocityRight) {
  posLeft = posLeft + left;
  posForLeft = posForLeft + forLeft;
  posRight = posRight + right;
  posForRight = posForRight + forRight;

  left_mtrAuto.move_relative(posLeft, velocityLeft);
  forward_left_mtrAuto.move_relative(posForLeft, velocityLeft);
  right_mtrAuto.move_relative(posRight, velocityRight);
  forward_right_mtrAuto.move_relative(posForRight, velocityRight);

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

  // PLAN A: may or may not work depending on how the while loops above work, since the loop they may run the entire function maybe idk, pros is weird and
  // other plans are accounting for that

  // // gets position for the next use of this function
  posLeft = left_mtrAuto.get_position();
  posForLeft = forward_left_mtrAuto.get_position();
  posRight = right_mtrAuto.get_position();
  posForRight = forward_right_mtrAuto.get_position();

  // comment this while loop if this doesn't work and it'll work with the comment in the autonomous function
  // PLAN B
  // while (
  //   ((left_mtrAuto.get_position() < (posLeft + 5)) && (left_mtrAuto.get_position() > (posLeft - 5)) &&
  //   (forward_left_mtrAuto.get_position() < (posForLeft + 5)) && (forward_left_mtrAuto.get_position() > (posForLeft - 5)) &&
  //   forward_right_mtrAuto.get_position() < (posForRight + 5)) && (forward_right_mtrAuto.get_position() > (posForRight - 5)) &&
  //   (right_mtrAuto.get_position() < (posRight + 5)) && (right_mtrAuto.get_position() > (posRight - 5))
  // )
  // {
  //   printf("Arrived at destination");
  //   calculatePosition();
  // }
}

void autonomous() {
  if (red == true) {
    if (front == true) {
      // PLAN C:
      // if this doesn't work, you can just switch it up so the next function is motors(2000...) and it'll run the same as 1000 since it's using the postion from before,
      // 1800 is one square
      motors(1500, 1500, 1500, 1500, 1000, 1000);
      // 800 is 45 degs
      // if this does work then the inputed value just adds on to the existing position which is much more intuitive
      delay(20);
      delay(20);
    }
  }
}
