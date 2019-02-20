#include "main.h"
#include "variables.h"
using namespace pros::literals;

void shoot() {
  launcher = 110;
  launcher2 = -110;
  delay(2000);
  intake = 127;
  delay(1000);
  launcher = 0;
  launcher2 = 0;
}

void flip(int time) {
  intake = -127;
  delay(time);
}
// Move the motors.
void drive(int left, int forLeft, int right, int forRight, int velocityLeft, int velocityRight) {
  left_mtr.move_absolute(left, velocityLeft);
  forward_left_mtr.move_absolute(forLeft, velocityLeft);
  right_mtr.move_absolute(right, velocityRight);
  forward_right_mtr.move_absolute(forRight, velocityRight);

  while (!((left_mtr.get_position() < (left + 5)) && (left_mtr.get_position() > (left - 5)))) {
    pros::delay(2);
  }

  while (!((forward_left_mtr.get_position() < (forLeft + 5)) && (forward_left_mtr.get_position() > (forLeft - 5)))) {
    pros::delay(2);
  }

  while (!((right_mtr.get_position() < (right + 5)) && (right_mtr.get_position() > (right - 5)))) {
    pros::delay(2);
  }

  while (!((forward_right_mtr.get_position() < (forRight + 5)) && (forward_right_mtr.get_position() > (forRight - 5)))) {
    pros::delay(2);
  }

  left_mtr.tare_position();
  forward_left_mtr.tare_position();
  right_mtr.tare_position();
  forward_right_mtr.tare_position();
}


void autonomous() {
  if (red == true) {
    if (front == true) {
      // 780 - 800 is about 90degs

      // flag and first cone
      // shoot();
      drive(1800, 1800, -1800, -1800, 200, 200);
      // delay(2000);
      // intakeFunc();
      // delay(2000);
      // motors(1500, 1500, 1500, 1500, 250, 250);
      // delay(2000);
      // motors(3600, 3600, -3600, -3600, 250, 250); // move towards bottom flag
      // delay(2000);
      // motors(-5400, -5400, 5400, 5400, 250, 250); // move back towards the cone
      // delay(2000);
      // motors(800, 800, 800, 800, 250, 250); // 45 degree rotation towards the cone
      // delay(2000);
      // motors(7500, 7500, -7500, -7500, 250, 250); // move towards the cone
      // delay(10000);

    }
  }
}


// possible improvements would be slow the velocity down when driving so it doesn't have as abrupt of a stop and won't screw it's position.
