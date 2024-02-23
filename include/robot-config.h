using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor cata1;
extern motor FR;
extern motor FL;
extern motor ML;
extern motor BL;
extern motor MR;
extern motor intake;
extern inertial imu;
extern motor BR;
extern pneumatics frontWings;
extern pneumatics backWings;
extern controller Controller1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );