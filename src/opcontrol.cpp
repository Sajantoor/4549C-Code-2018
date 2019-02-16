#include "main.h"
#include "motor.h"
using namespace pros::literals;
Controller master(CONTROLLER_MASTER);

int intakeValue;
int shootValue;

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
		launcher2 = -shootValue;
		intake = 0;
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
    }

		// Outtake
		if (master.get_digital(DIGITAL_R2)) {
			intake = -127;
			delay(20);
		}

		// Move forward
		if (master.get_digital(DIGITAL_UP)) {

    }

		// Rotate Right
		if (master.get_digital(DIGITAL_RIGHT)) {

		}

		// Rotate Left
		if (master.get_digital(DIGITAL_LEFT)) {

		}

		// Auto Switch
		if (master.get_digital_new_press(DIGITAL_X)) {
			autonomous();
			delay(20);
		}
	}
}
