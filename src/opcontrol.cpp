#include "main.h"

using namespace pros::literals;

Controller master(CONTROLLER_MASTER);
Motor left_mtr(9);
Motor forward_left_mtr(2);
Motor right_mtr(3);
Motor forward_right_mtr(4);
Motor crane(5);
Motor launcher(6);
Motor launcher2(7);
Motor intake(8);
int inverted = 0;

void opcontrol() {
	while (true) {
		int left = master.get_analog(ANALOG_LEFT_Y);
		lcd::set_text(1, "Left speed: " + std::to_string(left));
		int right = (master.get_analog(ANALOG_RIGHT_Y) * -1);
		lcd::set_text(2, "Right speed: " + std::to_string(right));
		// Stick variables
		if (inverted == 0) {
			left_mtr = left;
			forward_left_mtr = left;
			right_mtr = right;
			forward_right_mtr = right;
		}

		// if (inverted == 1) {
		// 	// Gets X position of the sticks
		// 	int leftX = master.get_analog(ANALOG_LEFT_X);
		// 	int rightX = master.get_analog(ANALOG_RIGHT_X);
		// 	// If the x position is greater than the Y position, then don't reverse
		// 	if (leftX < 0) {
		// 		leftX = (leftX * -1);
		// 	}
		//
		// 	if (rightX < 0) {
		// 		rightX = (rightX * -1);
		// 	}
		//
		// 	if (leftX < left) {
		// 		left_mtr = left;
		// 	} else {
		// 		left_mtr = (left * -1);
		// 	}
		//
		// 	if (rightX < right) {
		// 		right_mtr = right;
		// 		forward_right_mtr = right;
		// 	} else {
		// 		right_mtr = (right * -1);
		// 		forward_right_mtr = (right * -1);
		// 	}
		// }
		//
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

		// if (master.get_digital_new_press(DIGITAL_L1)) {
		// 	if (inverted == 0) {
		// 		inverted = 1;
		// 	} else {
		// 		inverted = 0;
		// 	}
		// 	pros::delay(20);
		// }

	}
}
