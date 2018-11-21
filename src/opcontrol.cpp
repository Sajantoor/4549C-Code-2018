#include "main.h"
using namespace pros::literals;

Controller master(CONTROLLER_MASTER);
Motor left_mtr(3);
Motor forward_left_mtr(4);
Motor right_mtr(9);
Motor forward_right_mtr(2);
Motor crane(5);
Motor launcher(6);
Motor launcher2(7);
Motor intake(8);
int autonomousMode = 1;

void motors(int left, int forLeft, int right, int forRight, float timeDelay) {
  // To save 4 - 5 lines and make the code more efficient.
  left_mtr = left;
  forward_left_mtr = forLeft;
  right_mtr = right;
  forward_right_mtr = forRight;
  pros::lcd::set_text(4, std::to_string(timeDelay));
  delay(timeDelay);
}

void rotate(float deg) {
  // Rotation uses a center point of rotation
  // The amount to move one degree while turning (in mileseoncs)
  float degTime = 2.95;
  float rotationTime = degTime * deg;
  // If the degrees are negative, the left motor will be given positive power.
  // If the degress are postive, the right motor will be given postive power.
  if (rotationTime > 0) {
    motors(127, 127, 127, 127, rotationTime);
  } else {
    rotationTime = (rotationTime * -1);
    motors(-127, -127, -127, -127, rotationTime);
  }
}

void moveMotors(float squares) {
  // Velocity is mileseconds to travel one square.
  float velocity = 505.625;
  float movementTime = squares * velocity;
  // time can't be negative
  if (movementTime < 0) {
    movementTime = (movementTime * -1);
  }
  // Forward and back movment with the appropriate time delay
  if (squares > 0) {
    motors(127, 127, -127, -127, movementTime);
    motors(-127, -127, 127, 127, 80.0);
  } else {
    motors(-127, -127, 127, 127, movementTime);
    motors(127, 127, -127, -127, 80.0);
  }
}

void autonomousClick() {
  moveMotors(3);
}

void opcontrol() {
	while (true) {
		int left = (master.get_analog(ANALOG_LEFT_Y));
		int right = (master.get_analog(ANALOG_RIGHT_Y) * -1);
		// Stick variables
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

		if (master.get_digital(DIGITAL_A)) {
			launcher = 127;
			launcher2 = -127;
			delay(20);
		}

		if (master.get_digital(DIGITAL_B)) {
			intake = 127;
			delay(20);
		}

		if (master.get_digital_new_press(DIGITAL_X)) {
			autonomousClick();
		}
	}
}
