#include "main.h"
using namespace pros::literals;
// Motors
// Motor left_mtrAuto(3);
// Motor forward_left_mtrAuto(4);
// Motor right_mtrAuto(9);
// Motor forward_right_mtrAuto(2);
// Motor craneAuto(5);
// Motor launcherAuto(6);
// Motor launcher2Auto(7);
// Motor intakeAuto(8);
// int autonomousMode = 2;
//
// void flip(int val) {
//   // 1 represents on, crane is up.
//   if (val == 1) {
//     craneAuto.move_voltage(12000);
//   //  x =  crane lift time
//   // delay(x);
//   }
//   // 0 represents off, crane is down.
//   if (val == 0) {
//     craneAuto.move_voltage(-12000);
//     // x = crane drop time
//     // delay(x);
//   }
// }
// // Move the motors.
// void motors(int left, int forLeft, int right, int forRight, float timeDelay) {
//   left_mtrAuto.move_voltage(left);
//   forward_left_mtrAuto.move_voltage(forLeft);
//   right_mtrAuto.move_voltage(right);
//   forward_right_mtrAuto.move_voltage(forRight);
//   delay(timeDelay);
//   left_mtrAuto.move_voltage(0);
//   forward_left_mtrAuto.move_voltage(0);
//   right_mtrAuto.move_voltage(0);
//   forward_right_mtrAuto.move_voltage(0);
// }
//
// void rotate(float deg) {
//   // Rotation uses a center point of rotation
//   // The amount to move one degree while turning (in milliseconds)
//   float degTime = 4.3;
//   float rotationTime = degTime * deg;
//   // If the degrees are negative, the left motor will be given positive power.
//   // If the degress are postive, the right motor will be given postive power.
//   if (rotationTime > 0) {
//     motors(12000, 12000, 12000, 12000, rotationTime);
//     // Cancels out deceleration
//     motors(-12000, -12000, -12000, -12000, 100);
//   } else {
//     rotationTime = (rotationTime * -1);
//     motors(-12000, -12000, -12000, -12000, rotationTime);
//     // Cancels out deceleration
//     motors(12000, 12000, 12000, 12000, 100);
//   }
// }
//
// void moveMotors(float squares) {
//   // Velocity is ms to travel one square.
//   float velocity = 505.625;
//   float movementTime = squares * velocity;
//   // time can't be negative
//   if (movementTime < 0) {
//     movementTime = (movementTime * -1);
//   }
//   // Forward and back movment with the appropriate time delay
//   if (squares > 0) {
//     motors(12000, 12000, -12000, -12000, movementTime);
//     // Previously
//     // motors(-127, -127, 127, 127, movementTime * 0.05);
//
//     // Effectively cancels deceleration
//     motors(-12000, -12000, 12000, 12000, 100);
//   } else {
//     motors(-12000, -12000, 12000, 12000, movementTime);
//     // Previously
//     // motors(127, 127, -127, -127, 80);
//
//     // Effectively cancels deceleration
//     motors(12000, 12000, -12000, -12000, 100);
//   }
// }

void autonomous() {
  // 165 is about 180 degrees
  // 90 degrees is 95 degrees

  // 1 is skills time
  // if (autonomousMode == 1) {
  //   moveMotors(2.3);
  //   delay(20);
  //   moveMotors(-1.5);
  //   delay(20);
  //   rotate(95);
  //   delay(20);
  //   moveMotors(1);
  //   delay(20);
  //   // flip first cone
  //   // Flip function here
  //   delay(20);
  //   rotate(-95);
  //   delay(20);
  //   moveMotors(1);
  //   delay(20);
  //   rotate(95);
  //   delay(20);
  //   moveMotors(2.5);
  //   delay(20);
  //   rotate(-95);
  //   delay(20);
  //   moveMotors(1);
  //   // hit second flag
  //   delay(20);
  //   moveMotors(-3);
  //   delay(20);
  //   rotate(95);
  //   delay(20);
  //   moveMotors(1); // or .5
  //   // flip function here
  //   // flip second cone
  //   delay(20);
  //   moveMotors(-1);
  //   delay(20);
  //   rotate(-95);
  //   delay(20);
  //   moveMotors(1);
  //   delay(20);
  //   rotate(-95);
  //   delay(20);
  //   moveMotors(3);
  //   delay(20);
  //   rotate(95);
  //   delay(20);
  //   moveMotors(4);
  //   delay(20);
  //   rotate(95);
  //   delay(20);
  //   moveMotors(2);
  //   delay(20);
  //   //flip cap here
  //   // flip 3rd cone here
  //   moveMotors(-2);
  //   delay(20);
  //   rotate(-95);
  //   delay(20);
  //   moveMotors(2);
  //   rotate(95);
  //   // infront of the platforms
  //   moveMotors(4);
  //   // my guess to get on the center plaform ^
  }
//   // Basic autonmous, just hits the flag if all else fails
//   if (autonomousMode == 2) {
//     moveMotors(2.3);
//     delay(20);
//     moveMotors(-1.5);
//   }
//
//   if (autonomousMode == 3) {
//     // this is our competition run
//   }
// }
