/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       caden                                                     */
/*    Created:      12/7/2023, 3:04:05 PM                                     */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// grab all external files
#include "vex.h"
#include "driver.cpp"
#include "arm.cpp"
#include "auto.cpp"

using namespace vex;

// A global instance of competition
competition Competition;


// external classes
Driver driver;

Arm arm;
// we pass in the driver class here, so that the autonomous code can access the drivetrain methods
Auto autonomousCode(driver);

// toggle variables have to be defined globally for some reason
bool driveTrainToggle = false;
bool autoTransToggle = true;
bool torqueToggle = false;
bool flingerToggle = false;
bool armToggle = false;
bool armHoldToggle = false;
bool wing1Toggle = false;
bool wing2Toggle = false;



// other functions

// function that toggles the drivetrain speed
void toggleDriveTrain() {
  driveTrainToggle = !driveTrainToggle;
}

// function that toggles the automatic transmission functionality
void toggleTransmission() {
  autoTransToggle = !autoTransToggle;
}

// function that toggles the torque mode in the transmission
void toggleTorque() {
  torqueToggle = !torqueToggle;
}
// function that toggles the flinger
void toggleFlinger() {
  flingerToggle = !flingerToggle;
}

// function that toggles the arm speed
void toggleArm() {
  armToggle = !armToggle;
}

// function that toggles whether the arm will hold iteself up or not
// this is because the arm sometimes draws too much power, and limits the drivetrain.
void toggleArmHold() {
  armHoldToggle = !armHoldToggle;
}

// function that toggles the right pneumatic flap
void toggleWing1() {
  wing1Toggle = !wing1Toggle;
}

// function that toggles the left pneumatic flap
void toggleWing2() {
  wing2Toggle = !wing2Toggle;
}

// sets the toggle functions
void setToggles() {
    // toggles the drive train speed
    Controller1.ButtonB.pressed(toggleDriveTrain);
    // toggles the transmission between automatic and manual
    Controller1.ButtonX.pressed(toggleTransmission)
    // toggles the torque mode for manual transmission
    Controller1.ButtonY.pressed(toggleTorque);

    // toggle the arm holding itself up
    Controller1.ButtonA.pressed(toggleArmHold);

    // toggles the flinger if the A button is pressed
    Controller2.ButtonA.pressed(toggleFlinger);
    // toggles the arm speed with two buttons
    Controller2.ButtonL1.pressed(toggleArm);
    Controller2.ButtonR1.pressed(toggleArm);
    // toggles the pnuematic flaps 
    Controller2.ButtonR2.pressed(toggleWing2);
    Controller2.ButtonL2.pressed(toggleWing1);
}

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
  autonomousCode.auto1();
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

void usercontrol(void) {
  // User control code here, inside the loop
  setToggles();
  while (1) {
    arm.manipulatorControl(armToggle, armHoldToggle, flingerToggle, wing1Toggle, wing2Toggle);
    driver.driverControl(driveTrainToggle, transmissionToggle, torqueToggle);

    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
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
