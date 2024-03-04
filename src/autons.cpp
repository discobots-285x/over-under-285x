

#include "vex.h"
#include "path.h"

void default_constants(){
  // Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
  chassis.set_drive_constants(10, 4.0, 0, 16, 0);
  chassis.set_heading_constants(6, .3, 0, 1.5, 0);
  chassis.set_turn_constants(12, .3, .01, 3, 15);
  chassis.set_swing_constants(12, .3, .001, 2, 15);

  // Each exit condition set is in the form (settle_error, settle_time, timeout).
  chassis.set_drive_exit_conditions(1.5, 300, 5000);
  chassis.set_turn_exit_conditions(1, 300, 3000);
  chassis.set_swing_exit_conditions(1, 300, 3000);

  FL.setBrake(brake);
  ML.setBrake(brake);
  BL.setBrake(brake);
  FR.setBrake(brake);
  MR.setBrake(brake);
  BR.setBrake(brake);
}

void odom_constants(){
  default_constants();
  chassis.drive_max_voltage = 12;
  chassis.drive_settle_error = 3;
}

void safe_auton(){
  chassis.drive_distance(-36);
}


void far_side() {
  odom_constants();
  chassis.set_coordinates(115, 12, 0);

  //get preload close to goal with wings
  intake.spin(reverse, 12, volt);
  frontWings.set(true);
  wait(350, msec);
  intake.stop();
  frontWings.set(false);

  //get to far middle triball, and push both in
  intake.spin(forward, 10, volt);
  chassis.drive_to_point(76, 65);
  chassis.turn_to_point(112, 63);
  frontWings.set(true);
  intake.spin(reverse, 12, volt);
  wait(150, msec);
  chassis.drive_to_point(112, 63);
  frontWings.set(false);

  //get close triball and release it around the match load zone
  chassis.turn_to_point(83, 49);
  intake.spin(forward, 12, volt);
  chassis.drive_to_point(83, 49);
  chassis.turn_to_point(124.5, 24);
  intake.stop();
  chassis.drive_to_point(124.5, 24);
  chassis.turn_to_angle(55);
  intake.spin(reverse, 12, volt);

  //free the match load bar triball
  backWings.set(true);
  wait(750, msec);
  chassis.turn_to_angle(-30, 12);
  intake.spin(reverse, 12, volt);
  chassis.drive_distance(4);
  backWings.set(false);
  intake.stop();
  wait(250, msec);
  chassis.turn_to_angle(-125);

  //push all in
  chassis.drive_to_point(132, 42, 12, 12);
  chassis.drive_distance(5);
}

void near_side() {
  odom_constants();
  chassis.set_coordinates(23.5, 12, 135);
  chassis.drive_to_point(12, 42);
  intake.spin(reverse, 12, volt);
  chassis.drive_to_point(25, 14);
  intake.stop();
  chassis.turn_to_angle(135);
  backWings.set(true);
  wait(250, msec);
  chassis.turn_to_angle(35, 8);
  backWings.set(false);
  wait(500, msec);
  chassis.turn_to_angle(-70);
  chassis.drive_distance(-24);
  chassis.turn_to_angle(-90);
  chassis.drive_distance(-15);
}

void near_side_elims(){
  intake.spin(reverse);
  odom_constants();
  chassis.set_coordinates(23, 12, 53);
  wait(250, msec);

  //dash to mid triballs and knock that shit
  frontWings.set(true);
  chassis.drive_to_point(56, 55);
  chassis.turn_to_angle(218.15);
  frontWings.set(false);

  //go back and free the match load triball
  chassis.drive_to_point(12, 22);
  chassis.turn_to_angle(-45);
  backWings.set(true);
  chassis.DriveL.spin(reverse, 12, volt);
  chassis.DriveR.spin(forward, 10, volt);
  wait(500, msec);
  chassis.DriveL.stop();
  chassis.DriveR.stop();
  backWings.set(false);

  //go and push alliance triball in
  chassis.turn_to_angle(135);
  chassis.drive_to_point(10, 41);

  //push match load and horizontal bar triballs over
  frontWings.set(true);
  intake.spin(reverse, 12, volt);
  chassis.drive_to_point(64, 10);
}

void skills_auton() {
  //push preloads into goal
  odom_constants();
  chassis.set_coordinates(23,12,135);
  chassis.drive_to_point(10, 42);

  //get to bar and match load
  chassis.drive_to_point(7, 22);
  chassis.turn_to_angle(250);
  frontWings.set(true);
  cata1.spin(forward, 10, volt);
  wait(60, seconds);
  cata1.stop();

/*
  //wedge shit over
  chassis.drive_to_point(57, 38);
  chassis.drive_to_point(57, 99);
  chassis.left_swing_to_angle(90);
  chassis.drive_distance(2);

  //get to other side
  frontWings.set(false);
  chassis.turn_to_point(17, 110);
  chassis.drive_to_point(17, 110);
  chassis.turn_to_angle(0);
  chassis.turn_to_point(44, 128);
  chassis.drive_distance(50);

  //push into left side of goal
  frontWings.set(true);
  intake.spin(reverse, 12, volt);
  chassis.drive_to_point(131, 95);
  frontWings.set(false);

  //push into goal front
  backWings.set(true);
  chassis.drive_to_point(94, 102.5);
  chassis.left_swing_to_angle(0);
  chassis.drive_distance(36);
  chassis.left_swing_to_angle(-90);
  chassis.drive_distance(36,-90, 12, 12);
  */
}


void drive_test(){
  chassis.drive_distance(60);
  chassis.drive_distance(-60);
}

void turn_test(){
  chassis.turn_to_angle(5);
  chassis.turn_to_angle(30);
  chassis.turn_to_angle(90);
  chassis.turn_to_angle(225);
  chassis.turn_to_angle(0);
}

void swing_test(){
  chassis.left_swing_to_angle(90);
  chassis.right_swing_to_angle(0);
}

void full_test(){
  chassis.drive_distance(24);
  chassis.turn_to_angle(-45);
  chassis.drive_distance(-36);
  chassis.right_swing_to_angle(-90);
  chassis.drive_distance(24);
  chassis.turn_to_angle(0);
}

void odom_test(){
  FL.setBrake(coast);
  ML.setBrake(coast);
  BL.setBrake(coast);
  FR.setBrake(coast);
  MR.setBrake(coast);
  BR.setBrake(coast);

  chassis.set_coordinates(115, 12, 0);
  while(1){
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(0,50, "X: %f", chassis.get_X_position());
    Brain.Screen.printAt(0,70, "Y: %f", chassis.get_Y_position());
    Brain.Screen.printAt(0,90, "Heading: %f", chassis.get_absolute_heading());
    Brain.Screen.printAt(0,110, "ForwardTracker: %f", chassis.get_ForwardTracker_position());
    Brain.Screen.printAt(0,130, "SidewaysTracker: %f", chassis.get_SidewaysTracker_position());
    task::sleep(20);
  }
}

void tank_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.turn_to_point(24, 24);
  chassis.drive_to_point(24,24);
  chassis.turn_to_angle(0);
  chassis.drive_to_point(0,0);
  chassis.turn_to_angle(0);
}