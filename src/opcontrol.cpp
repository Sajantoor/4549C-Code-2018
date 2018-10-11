#include "main.h"

using namespace pros::literals;

/**
/ This is a change to test git on this computer.
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
// 	auto left_mtr = 1_mtr;
// 	pros::Motor right_mtr(2);
// 	while (true) {
// 		int left = master.get_analog(ANALOG_LEFT_Y);
// 		int right = master.get_analog(ANALOG_RIGHT_Y);
//
//
// 		left_mtr = left;
// 		right_mtr = right;
// 		pros::delay(20);
// 	}
// }


void opcontrol() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	auto left_mtr = 1_mtr;
	auto forward_left_mtr = 2_mtr;
	pros::Motor right_mtr(3);
	pros::Motor forward_right_mtr2(4);
	pros::Motor arm(5);
	pros::Motor spinner(6);
	while (true) {


		int left = master.get_analog(ANALOG_LEFT_Y);
		//	int leftText = (left / 127) * 100;
		pros::lcd::set_text(1, "Left speed: " + std::to_string(left));
		int right = master.get_analog(ANALOG_RIGHT_Y);
		//	int rightText = (right / 127) * 100;
		pros::lcd::set_text(2, "Right speed: " + std::to_string(right));
		pros::lcd::set_text(3, "Actual Velocity: " + std::to_string(left_mtr.get_actual_velocity()));
		 printf("Actual velocity: %lf\n", left_mtr.get_actual_velocity());
		left_mtr = left;
		forward_left_mtr = (left * -1);
		arm = 0;
		right_mtr = right;
		forward_right_mtr2 = (right * -1);
		spinner = 0;
		pros::delay(20);
		left = 200;

		if (master.get_digital(DIGITAL_X)) {
			arm = -100;
			pros::delay(20);
		}

		if (master.get_digital(DIGITAL_B)) {
			arm = 100;
			pros::delay(20);
		}

		if (master.get_digital(DIGITAL_UP)) {
			spinner = -127;
			pros::delay(20);
		}

		if (master.get_digital(DIGITAL_DOWN)) {
			spinner = 127;
			pros::delay(20);
		}
	//	motor_move(1, controller_get_analog(pros::E_CONTROLLER_MASTER, pros::E_CONTROLLER_ANALOG_LEFT_Y));

	}
}
