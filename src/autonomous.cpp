#include "main.h"
// Motors
pros::Motor left_mtr(9);
pros::Motor forward_left_mtr(2);
pros::Motor right_mtr(3);
pros::Motor forward_right_mtr2(4);
pros::Motor crane(5);
pros::Motor launcher(6);
pros::Motor launcher2(7);

int autonomousMode = 0;

void moveMotors(int left, int right, int delay) {
  left_mtr = left;
  forward_left_mtr = left;
  right_mtr = right;
  forward_right_mtr2 = right;
  pros::delay(delay);
}

void autonomous() {
  while (autonomousMode == 0) {
    int left = 127;
    int right = 127;
    int delay = 3000;
    moveMotors(left, right, delay);
    autonomousMode = 1;
    pros::delay(20);
  }
}
