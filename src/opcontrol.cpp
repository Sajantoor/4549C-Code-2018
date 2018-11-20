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
  } else {
    rotationTime = (rotationTime * -1);
    left_mtr = 127;
    forward_left_mtr = 127;
    right_mtr = -127;
    forward_right_mtr = -127;
    delay(rotationTime);
  }
}

void moveMotors(float squares) {
  // Velocity is mileseconds to travel one square.
  pros::lcd::set_text(2, "Function is working");
  float velocity = 505.625;
  float movementTime = squares * velocity;
  pros::delay(20);
  // time can't be negative
  if (movementTime > 0) {
    movementTime = (movementTime * -1);
    pros::delay(20);
  }
  // Forward and back movment with the appropriate time delay
  if (squares > 0) {
    motors(127, 127, -127, -127, movementTime);
  } else {
    motors(-127, -127, 127, 127, movementTime);
  }
}


// void turn(float deg) {
//   // this function turns the motor, it uses a different point of rotation, different from the center point that rotation uses.
//   // float degTime = ???
//   float turnTime = degTime * deg;
//
//   if (turnTime < 0) {
//     left_mtr = 127;
//     forward_left_mtr = 127;
//     right_mtr = -127;
//     forward_right_mtr = -127;
//     delay(turnTime);
//   } else {
//     turnTime = (turnTime * -1);
//     left_mtr = 127;
//     forward_left_mtr = 127;
//     right_mtr = -127;
//     forward_right_mtr = -127;
//     delay(turnTime);
//   }
// }

void shoot() {

  // This function shoots the ball by given power to the spinner while preping the flywheel
}

// void inTake() {
//   intake = 127;
//   delay(?);
//   // this function intakes the ball by spinning the motor
// }
//
// void arm(int value) {
//   if (value == 1) {
//     // lift arm at the 90 degs position
//     crane = 110;
//     delay(?);
//   }
//
//   if (value == 0) {
//     crane = -110;
//     delay(?);
//   }
// }


void autonomousClick() {
  moveMotors(1.0);
  pros::lcd::set_text(1, "autonomous Function is working");
  pros::delay(20);
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
      pros::lcd::set_text(3, "Button is working!");
		}
	}
}
