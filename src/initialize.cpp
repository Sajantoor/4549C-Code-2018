#include "main.h"
using namespace pros::literals;

auto left_mtr = 3;
auto forward_left_mtr = 4;
auto right_mtr = 8;
auto forward_right_mtr = 1;
auto crane = 13;
auto launcher = 6;
auto launcher2 = 7;
auto intake = 5;
int autonomousMode = 1;
bool red = true;
bool front = true;

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

void initialize() {
	red = true;
	front = true;
	pros::lcd::initialize();
	pros::lcd::register_btn0_cb(redBlue);
	pros::lcd::register_btn1_cb(front_back);
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
