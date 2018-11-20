#include "main.h"
using namespace pros::literals;

void motors(int left, int fLeft, int right, int fRight, float timeDelay) {
  // To save 4 - 5 lines and make the code more efficient.
  left_mtr = left;
  forward_left_mtr = fLeft;
  right_mtr = right;
  forward_right_mtr = fRight;
  delay(timeDelay);
}

void rotate(float deg) {
  // Rotation uses a center point of rotation
  // The amount to move one degree while turning (in mileseoncs)
  float degTime = 3.37;
  float rotationTime = degTime * deg;

  // If the degrees are negative, the left motor will be given positive power.
  // If the degress are postive, the right motor will be given postive power.
  if (rotationTime < 0) {
    motors(127, 127, -127, -127, rotationTime);
    // left_mtr = 127;
    // forward_left_mtr = 127;
    // right_mtr = -127;
    // forward_right_mtr = -127;
    // delay(rotationTime);
  } else {
    rotationTime = (rotationTime * -1);
    left_mtr = 127;
    forward_left_mtr = 127;
    right_mtr = -127;
    forward_right_mtr = -127;
    delay(rotationTime);
  }
}

void moveMotors(float displacement) {
  // float velocity = ????
  // I have to calculate the time it takes to move one {some unit of measurement that's easy for us to use}
  float movementTime = displacement / velocity;
  // Haha nice physics formula. Haha Physics 11.

  // time can't be negative
  if (movementTime > 0) {
    movementTime = (movementTime * -1);
  }

  // Forward and back movment with the appropriate time delay
  if (displacement > 0) {
    left_mtr = 127;
    forward_left_mtr = 127;
    right_mtr = -127;
    forward_right_mtr = -127;
    delay(movementTime);
  } else {
    left_mtr = -127;
    forward_left_mtr = -127;
    right_mtr = 127;
    forward_right_mtr = 127;
    delay(movementTime);
  }
}


void turn(deg) {
  // this function turns the motor, it uses a different point of rotation, different from the center point that rotation uses.
  // float degTime = ???
  float turnTime = degTime * deg;

  if (turnTime < 0) {
    left_mtr = 127;
    forward_left_mtr = 127;
    right_mtr = -127;
    forward_right_mtr = -127;
    delay(turnTime);
  } else {
    turnTime = (turnTime * -1);
    left_mtr = 127;
    forward_left_mtr = 127;
    right_mtr = -127;
    forward_right_mtr = -127;
    delay(turnTime);
  }
}

void shoot() {

  // This function shoots the ball by given power to the spinner while preping the flywheel
}

void intake() {
  intake = 127;
  delay(?);
  // this function intakes the ball by spinning the motor
}

void arm(int value) {
  if (value == 1) {
    // lift arm at the 90 degs position
    crane = 110;
    delay(?);
  }

  if (value == 0) {
    crane = -110;
    delay(?);
  }
}
