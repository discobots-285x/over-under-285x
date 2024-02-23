#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor cata1 = motor(PORT2, ratio36_1, true);
motor FL = motor(PORT20, ratio6_1, false);
motor ML = motor(PORT9, ratio6_1, false);
motor BL = motor(PORT10, ratio6_1, true);
motor FR = motor(PORT11, ratio6_1, true);
motor MR = motor(PORT3, ratio6_1, true);
motor BR = motor(PORT1, ratio6_1, false);
motor intake = motor(PORT12, ratio6_1, true);
inertial imu = inertial(PORT4);
pneumatics backWings = pneumatics(Brain.ThreeWirePort.G);
pneumatics frontWings = pneumatics(Brain.ThreeWirePort.F);
controller Controller1 = controller(primary);
