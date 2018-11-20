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

void moveMotors(int left, int right, int delay) {
  left_mtr = left;
  forward_left_mtr = left;
  right_mtr = right;
  forward_right_mtr = right;
  delay(delay);
	delay(1000);
  autonomousMode = 1;
}

void autonomousClick() {
  while (autonomousMode == 0) {
    int left = 127;
    int right = 127;
    int delay = 3000;
    moveMotors(left, right, delay);
    delay(2000);
    autonomousMode = 1
  }
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

		if (master.get_digital(DIGITAL_X)) {
			autonomousClick();
		}
	}
}
