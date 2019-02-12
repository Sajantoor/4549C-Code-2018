#include "main.h"
using namespace pros::literals;
Controller master(CONTROLLER_MASTER);
Motor left_mtr(3);
Motor forward_left_mtr(4);
Motor right_mtr(8);
Motor forward_right_mtr(18);
Motor launcher(6);
Motor launcher2(7);
Motor intake(15);
int shootValue;
int shootValue2;

// Opcontrol
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
		launcher = shootValue;
		launcher2 = shootValue2;
		intake = 0;
		delay(20);

		// Launcher
		if (master.get_digital(DIGITAL_L1)) {
			shootValue = 127;
			shootValue2 = -127;
			delay(20);
		} else {
			while (shootValue >= 0) {
				shootValue = shootValue - 10;
				shootValue2 = shootValue2 + 10;
				delay(20);
			}

			while (shootValue < 0) {
				shootValue = 0;
				shootValue2 = 0;
				delay(20);
			}
		}

		// Rotate Right
		if (master.get_digital(DIGITAL_RIGHT)) {
      left_mtr = 100;
      forward_left_mtr = 100;
      right_mtr = 100;
      forward_right_mtr = 100;
			delay(20);
		}

		// Rotate Left
    if (master.get_digital(DIGITAL_LEFT)) {
      left_mtr = -100;
      forward_left_mtr = -100;
      right_mtr = -100;
      forward_right_mtr = -100;
      delay(20);
    }

		// Intake
    if (master.get_digital(DIGITAL_DOWN)) {
			intake = -127;
			delay(20);
    }

		// Outtake
		if (master.get_digital(DIGITAL_R1)) {
			intake = 127;
			delay(20);
		}

		// Move forward
		if (master.get_digital(DIGITAL_UP)) {
			left_mtr = 90;
      forward_left_mtr = 90;
      right_mtr = -90;
      forward_right_mtr = -90;
      delay(20);
    }

		// Auto Switch
		if (master.get_digital_new_press(DIGITAL_X)) {
			autonomous();
			delay(20);
		}
	}
}
