#include "main.h"
#include "variables.h"
using namespace pros::literals;

Motor left_mtr(3);
Motor forward_left_mtr(4);
Motor right_mtr(8);
Motor forward_right_mtr(18);
Motor launcher(6);
Motor launcher2(7);
Motor intake(20);
int autonomousMode = 1;
bool red = true;
bool front = true;
bool platform = true;

void redBlue() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		if (red) {
			pros::lcd::set_text(1, "Blue");
			red = false;
		} else {
			pros::lcd::set_text(1, "Red");
			red = true;
		}
	}
}

void front_back() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		if (front) {
			front = false;
			pros::lcd::set_text(2, "back");
		} else {
			front = true;
			pros::lcd::set_text(2, "front");
		}
	}
}

void platformFunc() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		if (front) {
			platform = false;
			pros::lcd::set_text(3, "no platform");
		} else {
			platform = true;
			pros::lcd::set_text(3, "platform");
		}
	}
}

void initialize() {
	red = true;
	front = true;
	pros::lcd::initialize();
	pros::lcd::register_btn0_cb(redBlue);
	pros::lcd::register_btn1_cb(front_back);
	pros::lcd::register_btn2_cb(platformFunc);
}


void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}
