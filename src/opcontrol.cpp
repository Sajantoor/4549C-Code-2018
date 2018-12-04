#include "main.h"
using namespace pros::literals;

Controller master(CONTROLLER_MASTER);
Motor left_mtr(3);
Motor forward_left_mtr(4);
Motor right_mtr(9);
Motor forward_right_mtr(2);
Motor crane(13);
Motor launcher(6);
Motor launcher2(7);
Motor intake(14);
int autonomousMode = 0;

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
    motors(-12000, -12000, -12000, -12000, 100);
  } else {
    rotationTime = (rotationTime * -1);
    motors(-12000, -12000, -12000, -12000, rotationTime);
    // Cancels out deceleration
    motors(12000, 12000, 12000, 12000, 100);
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
    // Previously
    // motors(-127, -127, 127, 127, movementTime * 0.05);

    // Effectively cancels deceleration
    motors(-12000, -12000, 12000, 12000, 100);
  } else {
    motors(-12000, -12000, 12000, 12000, movementTime);
    // Previously
    // motors(127, 127, -127, -127, 80);

    // Effectively cancels deceleration
    motors(12000, 12000, -12000, -12000, 100);
  }
}

void autonomousClick() {
  // 165 is about 180 degrees
  // 90 degrees is 95 degrees

  // 1 is skills time

  if (autonomousMode == 1) {
    flip(1);
    pros::delay(1000);
    moveMotors(2);
    delay(100);
    moveMotors(-1.5);
    flip(0);
  }

  if (autonomousMode == 2) {
    delay(100);
    rotate(95);
    delay(100);
    moveMotors(.5);
  }

  if (autonomousMode == 3) {
    delay(100);
    flip(2);
    delay(100);
    moveMotors(-.25);
    flip(0);
    delay(100);
  }

  if (autonomousMode == 3) {
    rotate(95);
    moveMotors(1);
    delay(100);
    rotate(-95);
    moveMotors(2);
  }

  if (autonomousMode == 4) {
    moveMotors(-2);
    delay(100);
    rotate(-95);
    delay(100);
  }

  if (autonomousMode == 5) {
    moveMotors(-1);
    delay(100);
    rotate(95);
    delay(100);
  }

  if (autonomousMode == 6) {
    moveMotors(4);
  }
}

void opcontrol() {
	while (true) {
		int left = (master.get_analog(ANALOG_LEFT_Y));
		int right = (master.get_analog(ANALOG_RIGHT_Y) * -1);
		// Stick variables
    //left_mtr.move(master.get_analog(ANALOG_LEFT_Y));
		left_mtr = left;
		forward_left_mtr = left;
		right_mtr = right;
		forward_right_mtr = right;
		// Reset button functions
		crane = 0;
		launcher = 0;
		launcher2 = 0;
		intake = 0;
		delay(20);

		if (master.get_digital(DIGITAL_R2)) {
			crane = 110;
			delay(20);
		}

		if (master.get_digital(DIGITAL_L2)) {
			crane = -110;
			delay(20);
		}

		if (master.get_digital(DIGITAL_L1)) {
			 launcher = 127;
		   launcher2 = -127;
      // launcher.move_voltage(12000);
      // launcher2.move_voltage(-12000);
			delay(20);
		}

		if (master.get_digital(DIGITAL_R1)) {
			intake = 127;
			delay(20);
		}

		if (master.get_digital_new_press(DIGITAL_X)) {
			autonomousClick();
      autonomousMode++;
		}
	}
}

// Fixes: Add a way to move diagonally
// Flipping cones and moving at the same time.
// Flipping caps speed
// Shooter once shooter is built
