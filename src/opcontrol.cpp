#include "main.h"
using namespace pros::literals;
Controller master(CONTROLLER_MASTER);

// Opcontrol
void opcontrol() {
	while (true) {
		int left = (master.get_analog(ANALOG_LEFT_Y));
		int right = (master.get_analog(ANALOG_RIGHT_Y) * -1);
		// Stick variables
    //left_mtr.move(master.get_analog(ANALOG_LEFT_Y));
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

		if (master.get_digital(DIGITAL_L1)) {
			 launcher = 127;
		   launcher2 = -127;
      // launcher.move_voltage(12000);
      // launcher2.move_voltage(-12000);
			delay(20);
		}
      //Arda's design if needed remove
		if (master.get_digital(DIGITAL_RIGHT)) {
      left_mtr = 100;
      forward_left_mtr = 100;
      right_mtr = 100;
      forward_right_mtr = 100;
			delay(20);
		}

  //Arda's design if needed remove
    if (master.get_digital(DIGITAL_LEFT)) {
      left_mtr = -100;
      forward_left_mtr = -100;
      right_mtr = -100;
      forward_right_mtr = -100;
      delay(20);
    }

    if (master.get_digital(DIGITAL_DOWN)) {
			intake = -127;
			delay(20);
    }

    if (master.get_digital(DIGITAL_R1)) {
      intake = 127;
      delay(20);
    }
	}
}
