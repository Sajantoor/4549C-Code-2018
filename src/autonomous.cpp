#include "main.h"
#include "variables.h"
using namespace pros::literals;

void shoot(int shootDelay, int intakeTime) {
  launcher = 110;
  launcher2 = -110;
  delay(shootDelay);
  intake = 127;
  delay(intakeTime);
  launcher = 0;
  launcher2 = 0;
  intake = 0;
}

void intakeFunc(int time) {
  intake = 127;
  delay(time);
  intake = 0;
}

void flip(int time) {
  intake = -100;
  delay(time);
  intake = 0;
}

void park(int left, int forLeft, int right, int forRight, int velocityLeft, int velocityRight, int time) {
  left_mtr.move_absolute(left, velocityLeft);
  forward_left_mtr.move_absolute(forLeft, velocityLeft);
  right_mtr.move_absolute(right, velocityRight);
  forward_right_mtr.move_absolute(forRight, velocityRight);
  delay(time);
}
// Move the motors.
void drive(int left, int forLeft, int right, int forRight, int velocityLeft, int velocityRight, bool flipVal, bool intakeVal) {
  left_mtr.move_absolute(left, velocityLeft);
  forward_left_mtr.move_absolute(forLeft, velocityLeft);
  right_mtr.move_absolute(right, velocityRight);
  forward_right_mtr.move_absolute(forRight, velocityRight);

  if (flipVal) {
    flip(2);
  }

  if (intakeVal) {
    intakeFunc(2);
  }

  while (!((left_mtr.get_position() < (left + 5)) && (left_mtr.get_position() > (left - 5)))) {
    pros::delay(2);
  }

  while (!((forward_left_mtr.get_position() < (forLeft + 5)) && (forward_left_mtr.get_position() > (forLeft - 5)))) {
    pros::delay(2);
  }

  while (!((right_mtr.get_position() < (right + 5)) && (right_mtr.get_position() > (right - 5)))) {
    pros::delay(2);
  }

  while (!((forward_right_mtr.get_position() < (forRight + 5)) && (forward_right_mtr.get_position() > (forRight - 5)))) {
    pros::delay(2);
  }

  left_mtr.tare_position();
  forward_left_mtr.tare_position();
  right_mtr.tare_position();
  forward_right_mtr.tare_position();
}


void autonomous() {
  if (platform) {
    if (red) {
      if (front) {
        // RED FRONT AUTO
        // Drive forwards and intakes a ball, flips cap
        if (autonomousMode == 1) {
          left_mtr.tare_position();
          forward_left_mtr.tare_position();
          right_mtr.tare_position();
          forward_right_mtr.tare_position();
          drive(3200, 3200, -3200, -3200, 150, 150, false, true);
          intakeFunc(500);
          delay(20);
          autonomousMode++;
          autonomous();
          delay(20);
        }

        // Drives back and returns to starting position, hitting the wall
        if (autonomousMode == 2) {
          drive(-3400, -3400, 3400, 3400, 180, 180, false, false);
          delay(20);
          autonomousMode++;
          autonomous();
          delay(20);
        }

        // Moves forward rotates back facing the flags, lined up
        if (autonomousMode == 3) {
          drive(730, 730, -730, -730, 200, 200, false, false);
          delay(20);
          drive(760, 760, 760, 760, 150, 150, false, false);
          delay(20);
          autonomousMode++;
          autonomous();
          delay(20);
        }

        // Shoots middle flag
        if (autonomousMode == 4) {
          shoot(850, 300);
          delay(20);
          autonomousMode++;
          autonomous();
          delay(20);
        }

        // Shoots top flag
        if (autonomousMode == 5) {
          shoot(1500, 2000);
          delay(20);
          autonomousMode++;
          autonomous();
          delay(20);
        }

        // Moves towards platform and rotates towards platform
        if (autonomousMode == 6) {
          drive(1700, 1700, -1700, -1700, 200, 200, false, false);
          delay(20);
          drive(-800, -800, -800, -800, 200, 200, false, false);
          delay(20);
          autonomousMode++;
          autonomous();
          delay(20);
        }

        // Parks
        if (autonomousMode == 7) {
          park(4600, 4600, -4600, -4600, 200, 200, 2000);
          delay(20);
          autonomousMode++;
          delay(20);
        }
      }
    }

    if (red) {
      if (front == false) {
        // RED BACK AUTO
       // Go front, grab ball and flip cap
       if (autonomousMode == 1) {

         drive(3200, 3200, -3200, -3200, 150, 150, false, true);
         intakeFunc(700);
         delay(20);
       }

       // Move back one square, rotate facing the wall
       if (autonomousMode == 2) {
         drive(-1800, -1800, 1800, 1800, 200, 200, false, false);
         delay(20);
         drive(-750, -750, -750, -750, 200, 200, false, false);
         delay(20);
       }
       // Moves forward rotates back facing the cap
       if (autonomousMode == 3) {
         drive(1800, 1800, -1800, -1800, 200, 200, false, false);
         delay(20);
         drive(750, 750, 750, 750, 200, 200, false, false);
       }
       // Moves towards cone and flips cap
       if (autonomousMode == 4) {
         drive(1800, 1800, -1800, -1800, 200, 200, true, false);
         delay(20);
         flip(1000);
       }
       // backs into the wall and moves forward
       if (autonomousMode == 5) {
         drive(-5400, -5400, 5400, 5400, 200, 200, false, false);
         delay(20);
         drive(700, 700, -700, -700, 200, 200, false, false);
       }

       // rotates and moves towards platform
       if (autonomousMode == 5) {
         drive(750, 750, 750, 750, 200, 200, false, false);
         delay(20);
         drive(3600, 3600, -3600, -3600, 200, 200, false, false);
       }
       // Rotates toward platform and parks
       if (autonomousMode == 6) {
         drive(-750, -750, -750, -750, 200, 200, false, false);
         delay(20);
         drive(3600, 3600, -3600, -3600, 200, 200, false, false);
       }
      }
    }

    if (red == false) {
      if (front) {
        //  BLUE FRONT AUTO
      }
    }

    if (red == false) {
      if (front == false) {
        //  BLUE BACK AUO
      }
    }


  } else {
    // no platform
  }



}

// possible improvements would be slow the velocity down when driving so it doesn't have as abrupt of a stop and won't screw it's position.
