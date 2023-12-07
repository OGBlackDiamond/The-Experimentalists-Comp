using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor leftFrontDrive;
extern motor leftBackDrive;
extern motor rightFrontDrive;
extern motor rightBackDrive;


/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );