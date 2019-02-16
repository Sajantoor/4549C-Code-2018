#include "main.h"
#include "variables.h"
using namespace pros::literals;
Controller master(CONTROLLER_MASTER);
int intakeValue;
int shootValue;

// Controls
void opcontrol() {
	while (true) {
		int left = master.get_analog(ANALOG_LEFT_Y);
		int right = master.get_analog(ANALOG_RIGHT_Y);
		// Stick variables
		left_mtr = left;
		forward_left_mtr = left;
		right_mtr = -right;
		forward_right_mtr = -right;
		// Reset button functions
		launcher = shootValue;
		launcher2 = -shootValue;
		intake = intakeValue;
		delay(20);

		// Launcher
		if (master.get_digital(DIGITAL_L2)) {
			shootValue = 127;
			delay(20);
		} else {
			while (shootValue > 0) {
				shootValue -= 10;
				delay(20);
			}

			while (shootValue < 0) {
				shootValue = 0;
				delay(20);
			}
		}

		// Intake
    if (master.get_digital(DIGITAL_R1)) {
			intake = 127;
			delay(20);
    } else {
			while (intakeValue > 0) {
				intakeValue -= 20;
				delay(20);
			}

			while (intakeValue < 0) {
				intakeValue = 0;
				delay(20);
			}
		}

		// Outtake
		if (master.get_digital(DIGITAL_R2)) {
			intakeValue = -127;
			delay(20);
		} else {
			while (intakeValue < 0) {
				intakeValue += 20;
				delay(20);
			}

			while (intakeValue > 0) {
				intakeValue = 0;
				delay(20);
			}
		}

		// Move forward
		if (master.get_digital(DIGITAL_UP)) {
			left_mtr = 127;
			forward_left_mtr = 127;
			right_mtr = -127;
			forward_right_mtr = -127;
			delay(20);
    }

		// Rotate Right
		if (master.get_digital(DIGITAL_RIGHT)) {
			left_mtr = 127;
			forward_left_mtr = 127;
			right_mtr = 127;
			forward_right_mtr = 127;
			delay(20);
		}

		// Rotate Left
		if (master.get_digital(DIGITAL_LEFT)) {
			left_mtr = -127;
			forward_left_mtr = -127;
			right_mtr = -127;
			forward_right_mtr = -127;
			delay(20);
		}

		if (master.get_digital(DIGITAL_DOWN)) {
			left_mtr = -127;
			forward_left_mtr = -127;
			right_mtr = 127;
			forward_right_mtr = 127;
			delay(20);
		}

		// Auto Switch
		if (master.get_digital_new_press(DIGITAL_X)) {
			autonomous();
			delay(20);
		}
	}
}
