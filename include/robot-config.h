using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern controller Controller2;

extern motor leftFrontDrive;
extern motor leftBackDrive;
extern motor rightFrontDrive;
extern motor rightBackDrive;
//extern motor leftTrans;
//extern motor rightTrans;
extern motor turret;
extern motor shoulder;
extern motor elbow;
extern motor flinger;
extern digital_out wing1;
extern digital_out wing2;


/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );