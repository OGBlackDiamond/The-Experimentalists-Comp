#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
controller Controller2 = controller(partner);

motor leftFrontDrive = motor(PORT11, ratio18_1, false);
motor leftBackDrive = motor(PORT20, ratio18_1, false);
motor rightFrontDrive = motor(PORT1, ratio18_1, true);
motor rightBackDrive = motor(PORT10, ratio18_1, true);
motor turret = motor(PORT15, ratio18_1, false);
motor shoulder = motor(PORT6, ratio6_1, false);
motor elbow = motor(PORT3, ratio18_1, false);
motor flinger = motor(PORT2, ratio36_1, false);


// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
* Used to initialize code/tasks/devices added using tools in VEXcode Pro.
* 
* This should be called at the start of your int main function.
*/
void vexcodeInit( void ) {
    //
}