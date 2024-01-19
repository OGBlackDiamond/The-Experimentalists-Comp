#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
controller Controller2 = controller(partner);

motor leftFrontDrive = motor(PORT2, ratio18_1, true);
motor leftBackDrive = motor(PORT1, ratio18_1, true);
motor rightFrontDrive = motor(PORT11, ratio18_1, false);
motor rightBackDrive = motor(PORT12, ratio18_1, false);
motor leftTrans = motor(PORT17, ratio18_1, false);
motor rightTrans = motor(PORT18, ratio18_1, true);
motor turret = motor(PORT19, ratio18_1, false);
motor shoulder = motor(PORT6, ratio6_1, false);
motor elbow = motor(PORT3, ratio18_1, false);
motor flinger = motor(PORT2, ratio36_1, false);
motor lift1 = motor(PORT10, ratio6_1, true);
motor lift2 = motor(PORT20, ratio6_1, false);
digital_out wing1 = digital_out(Brain.ThreeWirePort.C);
digital_out wing2 = digital_out(Brain.ThreeWirePort.B);


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