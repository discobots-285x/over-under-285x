#include "vex.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// cata1                motor         2               
// FR                   motor         20              
// FL                   motor         11              
// BL                   motor         1               
// intake               motor         12              
// imu                  inertial      21              
// DAblocker            digital_out   H               
// BR             tor         10              
// SAblocker            digital_out   G               
// wings                digital_out   F               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

using namespace vex;
competition Competition;

/*---------------------------------------------------------------------------*/
/*                             VEXcode Config                                */
/*                                                                           */
/*  Before you do anything else, start by configuring your motors and        */
/*  sensors using the V5 port icon in the top right of the screen. Doing     */
/*  so will update robot-config.cpp and robot-config.h automatically, so     */
/*  you don't have to. Ensure that your motors are reversed properly. For    */
/*  the drive, spinning all motors forward should drive the robot forward.   */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*                             JAR-Template Config                           */
/*                                                                           */
/*  Where all the magic happens. Follow the instructions below to input      */
/*  all the physical constants and values for your robot. You should         */
/*  already have configured your robot manually with the sidebar configurer. */
/*---------------------------------------------------------------------------*/

Drive chassis(

//Specify your drive setup below. There are seven options:
//ZERO_TRACKER_NO_ODOM, ZERO_TRACKER_ODOM, TANK_ONE_ENCODER, TANK_ONE_ROTATION, TANK_TWO_ENCODER, TANK_TWO_ROTATION, HOLONOMIC_TWO_ENCODER, and HOLONOMIC_TWO_ROTATION
//For example, if you are not using odometry, put ZERO_TRACKER_NO_ODOM below:
ZERO_TRACKER_ODOM,

//Add the names of your Drive motors into the motor groups below, separated by commas, i.e. motor_group(Motor1,Motor2,Motor3).
//You will input whatever motor names you chose when you configured your robot using the sidebar configurer, they don't have to be "Motor1" and "Motor2".

//Left Motors:
motor_group(FL, ML, BL),

//Right Motors:
motor_group(FR, MR, BR),

//Specify the PORT NUMBER of your inertial sensor, in PORT format (i.e. "PORT1", not simply "1"):
PORT4,

//Input your wheel diameter. (4" omnis are actually closer to 4.125"):
3.25,

//External ratio, must be in decimal, in the format of input teeth/output teeth.
//If your motor has an 84-tooth gear and your wheel has a 60-tooth gear, this value will be 1.4.
//If the motor drives the wheel directly, this value is 1:
0.6,

//Gyro scale, this is what your gyro reads when you spin the robot 360 degrees.
//For most cases 360 will do fine here, but this scale factor can be very helpful when precision is necessary.
360,

/*---------------------------------------------------------------------------*/
/*                                  PAUSE!                                   */
/*                                                                           */
/*  The rest of the drive constructor is for robots using POSITION TRACKING. */
/*  If you are not using position tracking, leave the rest of the values as  */
/*  they are.                                                                */
/*---------------------------------------------------------------------------*/

//If you are using ZERO_TRACKER_ODOM, you ONLY need to adjust the FORWARD TRACKER CENTER DISTANCE.

//FOR HOLONOMIC DRIVES ONLY: Input your drive motors by position. This is only necessary for holonomic drives, otherwise this section can be left alone.
//LF:      //RF:    
PORT1,     -PORT2,

//LB:      //RB: 
PORT3,     -PORT4,

//If you are using position tracking, this is the Forward Tracker port (the tracker which runs parallel to the direction of the chassis).
//If this is a rotation sensor, enter it in "PORT1" format, inputting the port below.
//If this is an encoder, enter the port as an integer. Triport A will be a "1", Triport B will be a "2", etc.
PORT4,

//Input the Forward Tracker diameter (reverse it to make the direction switch):
2.75,

//Input Forward Tracker center distance (a positive distance corresponds to a tracker on the right side of the robot, negative is left.)
//For a zero tracker tank drive with odom, put the positive distance from the center of the robot to the right side of the drive.
//This distance is in inches:
6.5,

//Input the Sideways Tracker Port, following the same steps as the Forward Tracker Port:
1,

//Sideways tracker diameter (reverse to make the direction switch):
-2.75,

//Sideways tracker center distance (positive distance is behind the center of the robot, negative is in front):
5.5

);

int current_auton_selection = 0;
bool auto_started = false;

void pre_auton(void) {
  default_constants();

  while(auto_started == false){            //Changing the names below will only change their names on the
    Brain.Screen.clearScreen();            //brain screen for auton selection.
    switch(current_auton_selection){       //Tap the brain screen to cycle through autons.
      case 0:
        Brain.Screen.printAt(50, 50, "Safe Auton");
        break;
      case 1:
        Brain.Screen.printAt(50, 50, "Far Side");
        break;
      case 2:
        Brain.Screen.printAt(50, 50, "Near Side");
        break;
      case 3:
        Brain.Screen.printAt(50, 50, "Far Side Elims");
        break;
      case 4:
        Brain.Screen.printAt(50, 50, "Near Side Elims");
        break;
    }
    if(Brain.Screen.pressing()){
      while(Brain.Screen.pressing()) {}
      current_auton_selection ++;
    } else if (current_auton_selection == 8){
      current_auton_selection = 0;
    }
    task::sleep(10);
  }
}

void autonomous(void) {
  auto_started = true;
  switch(current_auton_selection){  
    case 0:
      far_side(); //This is the default auton, if you don't select from the brain.
      break;        //Change these to be your own auton functions in order to use the auton selector.
    case 1:         //Tap the screen to cycle through autons.
      far_side();
      break;
    case 2:
      near_side();
      break;
    case 3:
      far_side_elims();
      break;
    case 4:
      near_side_elims();
      break;
 }
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

bool intakeLatch = false;
bool cataLatch = false;
bool backWingsLatch = false;
bool frontWingsLatch = false;


bool cataToggle = false;
bool backWingsToggle = false;
bool frontWingsToggle = false;


void usercontrol(void) {
  //Replace this line with chassis.control_tank(); for tank drive 
  //or chassis.control_holonomic(); for holo drive.

  // User control code here, inside the loop
  while (1) {
    chassis.control_arcade();
    if (Controller1.ButtonR2.pressing()) {
      intake.spin(forward, 12, volt);
      intakeLatch = false;
    } else if (Controller1.ButtonR1.pressing()) {
      intake.spin(reverse, 12, volt);
      intakeLatch = false;
    } else if (!intakeLatch) {
      intake.stop();
      intakeLatch = true;
    }

    if (cataToggle){
      cata1.spin(forward, 12, volt);
    } else {
      cata1.stop();
    }

    if (Controller1.ButtonL2.pressing()) {
      if(!cataLatch){ //flip the toggle one time and set the latch
        cataToggle = !cataToggle;
        cataLatch = true;
      }
    } else {
      cataLatch = false;
    }

    if (backWingsToggle){
      backWings.set(true);
    } else {
      backWings.set(false);
    }

    if (Controller1.ButtonA.pressing()) {
      if(!backWingsLatch){ //flip the toggle one time and set the latch
        backWingsToggle = !backWingsToggle;
        backWingsLatch = true;
      }
    } else {
      //Once the BumperA is released then then release the latch too
      backWingsLatch = false;
    }


    if (frontWingsToggle){
      frontWings.set(true);
    } else {
      frontWings.set(false);
    }

    if (Controller1.ButtonL1.pressing()) {
      if(!frontWingsLatch){ //flip the toggle one time and set the latch
        frontWingsToggle = !frontWingsToggle;
        frontWingsLatch = true;
      }
    } else {
      //Once the BumperA is released then then release the latch too
      frontWingsLatch = false;
    }
  // wait before repeating the process
  wait(20, msec);
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}