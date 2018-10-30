#include "main.h"

using namespace pros::literals;

pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Motor left_mtr(9);
pros::Motor forward_left_mtr(2);
pros::Motor right_mtr(3);
pros::Motor forward_right_mtr2(4);
pros::Motor crane(5);
pros::Motor launcher(6);
pros::Motor launcher2(7);
int inverted = 0;

void opcontrol() {
	while (true) {
		int left = master.get_analog(ANALOG_LEFT_Y);
		pros::lcd::set_text(1, "Left speed: " + std::to_string(left));
		int right = master.get_analog(ANALOG_RIGHT_Y);
		pros::lcd::set_text(2, "Right speed: " + std::to_string(right));
		// Stick variables
		if (inverted == 0) {
			left_mtr = left;
			forward_left_mtr = left;
			right_mtr = (right * -1);
			forward_right_mtr2 = (right * -1);
		}

		if (inverted == 1) {
			left_mtr = (left * -1);
			forward_left_mtr = (left * -1);
			right_mtr = right;
			forward_right_mtr2 = right;
		}
		// Reset button functions
		crane = 0;
		launcher = 0;
		launcher2 = 0;
		pros::delay(20);

		if (master.get_digital(DIGITAL_R2)) {
			crane = 100;
			pros::delay(20);
		}

		if (master.get_digital(DIGITAL_L2)) {
			crane = -100;
			pros::delay(20);
		}

		if (master.get_digital(DIGITAL_A)) {
			launcher = 127;
			launcher2 = -127;
			pros::delay(20);
		}

		if (master.get_digital_new_press(DIGITAL_L1)) {
			if (inverted == 0) {
				inverted = 1;
			} else {
				inverted = 0;
			}
			pros::delay(20);
		}
	}
}
