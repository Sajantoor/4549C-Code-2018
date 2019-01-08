#include "main.h"
using namespace pros::literals;
/*
void flip(int val) {
  // 1 represents on, crane is up.
  if (val == 1) {
    crane.move_voltage(12000);
    delay(200);
    crane.move_voltage(0);
  }
  // flip cap value
  if (val == 2) {
    crane.move_voltage(12000);
    delay(350);
    crane.move_voltage(0);
  }
  // 0 represents off, crane is down.
  if (val == 0) {
    crane.move_voltage(-12000);
    delay(70);
    crane.move_voltage(0);
  }
}
// Move the motors.
void motors(int left, int forLeft, int right, int forRight, float timeDelay) {
  left_mtr.move_voltage(left);
  forward_left_mtr.move_voltage(forLeft);
  right_mtr.move_voltage(right);
  forward_right_mtr.move_voltage(forRight);
  delay(timeDelay);
  left_mtr.move_voltage(0);
  forward_left_mtr.move_voltage(0);
  right_mtr.move_voltage(0);
  forward_right_mtr.move_voltage(0);
}

void rotate(float deg) {
  // Rotation uses a center point of rotation
  // The amount to move one degree while turning (in milliseconds)
  float degTime = 4.3;
  float rotationTime = degTime * deg;
  // If the degrees are negative, the left motor will be given positive power.
  // If the degress are postive, the right motor will be given postive power.
  if (rotationTime > 0) {
    motors(12000, 12000, 12000, 12000, rotationTime);
    // Cancels out deceleration
    motors(-10000, -10000, -10000, -10000, 100);
  } else {
    rotationTime = (rotationTime * -1);
    motors(-12000, -12000, -12000, -12000, rotationTime);
    // Cancels out deceleration
    motors(10000, 10000, 10000, 10000, 100);
  }
}

void moveMotors(float squares) {
  // Velocity is ms to travel one square.
  float velocity = 503.625;
  float movementTime = squares * velocity;
  // time can't be negative
  if (movementTime < 0) {
    movementTime = (movementTime * -1);
  }
  // Forward and back movment with the appropriate time delay
  if (squares > 0) {
    motors(12000, 12000, -12000, -12000, movementTime);
    delay(300);
    // Previously
    // motors(-127, -127, 127, 127, movementTime * 0.05);
    // Effectively cancels deceleration
    motors(-5000, -5000, 5000, 5000, 60);
  } else {
    motors(-12000, -12000, 12000, 12000, movementTime);
    // Previously
    // motors(127, 127, -127, -127, 80);
    delay(300);
    // Effectively cancels deceleration
    motors(5000, 5000, -5000, -5000, 60);
  }
}

void autonomous() {
  // 165 is about 180 degrees
  // 90 degrees is 95 degrees

  // 1 is skills time
  // Hit flag and move back
  if (red == true) {
    if (front == true) {
      if (autonomousMode == 1) {
        flip(1);
        pros::delay(300);
        moveMotors(1.4);
        delay(500);
        moveMotors(-0.5);
        flip(0);
        delay(300);
        autonomousMode++;
        autonomous();
      }
      // Move forward infront of cone
      if (autonomousMode == 2) {
        rotate(70);
        delay(500);
        moveMotors(-0.2);
        delay(500);
        moveMotors(0.5);
        delay(500);
        autonomousMode++;
        autonomous();
      }
      // Flip cone and move back
      if (autonomousMode == 3) {
        flip(2);
        delay(100);
        moveMotors(-1);
        delay(100);
        flip(0);
        moveMotors(.25);
        autonomousMode++;
        autonomous();
      }
      // Turn to other cone and hit said cone
      if (autonomousMode == 4) {
        rotate(85);
        delay(500);
        moveMotors(1.95);
        delay(500);
        rotate(-90);
        delay(500);
        moveMotors(-1.25);
        delay(200);
        moveMotors(0.5);
        delay(300);
        moveMotors(2.25);
        autonomousMode++;
      }
    }

    if (front == false) {
      if (autonomousMode == 1){
        moveMotors(1.5);
        delay(500);
        flip(2);
        delay(300);
        moveMotors(-1);
        delay(500);
        autonomousMode++;
        autonomous();
      }

      if (autonomousMode == 2) {
        rotate(75);
        delay(500);
        moveMotors(0.5);
        delay(500);
        rotate(-75);
        delay(500);
        moveMotors(1);
        delay(500);
        flip(0);
        delay(600);
        moveMotors(-1);
        autonomousMode++;
      }
    }
  }
}
*/
void autonomous() {}
