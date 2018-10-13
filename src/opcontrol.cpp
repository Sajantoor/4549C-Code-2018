#include "main.h"

using namespace pros::literals;

void opcontrol() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	auto left_mtr = 1_mtr;
	auto forward_left_mtr = 2_mtr;
	pros::Motor right_mtr(3);
	pros::Motor forward_right_mtr2(4);
	pros::Motor crane(5);
	pros::Motor crane2(6);
	pros::Motor flipper(7);

	while (true) {
		int left = (master.get_analog(ANALOG_LEFT_Y)) * 0.8;
		pros::lcd::set_text(1, "Left speed: " + std::to_string(left));
		int right = (master.get_analog(ANALOG_RIGHT_Y)) * 0.8;
		pros::lcd::set_text(2, "Right speed: " + std::to_string(right));

		// Stick variables
		left_mtr = left;
		forward_left_mtr = (left * -1);
		right_mtr = (right * -1);
		forward_right_mtr2 = (right * -1);
		// Reset button functions
		crane = 0;
		crane2 = 0;
		flipper = 0;
		pros::delay(20);

		if (master.get_digital(DIGITAL_R1)) {
			crane = 100;
		 	crane2 = -100;
			pros::delay(20);
		}

		if (master.get_digital(DIGITAL_L1)) {
			crane = -100;
			crane2 = 100;
			pros::delay(20);
		}

		if (master.get_digital(DIGITAL_R2)) {
			flipper = 100;
			pros::delay(20);
		}

		if (master.get_digital(DIGITAL_L2)) {
			flipper = -100;
			pros::delay(20);
		}
	}
}
