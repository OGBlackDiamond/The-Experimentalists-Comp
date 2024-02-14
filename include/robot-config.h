using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern controller Controller2;

extern motor leftRing;
extern motor leftSun;
extern motor rightRing;
extern motor rightSun;
extern motor shoulder;
extern motor flinger;
extern motor lift1;
extern motor lift2;
extern digital_out wing1;
extern digital_out wing2;


/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );