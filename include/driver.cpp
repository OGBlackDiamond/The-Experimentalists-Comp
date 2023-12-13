/*
  The driver class
  All of the control for the driver will be placed on the first controller
*/
class Driver {

  public:

    Driver() {}

    void driverControl(bool toggleDriveTrain) {
        // refresh control stick values
        updateControls(toggleDriveTrain);
        // spin the motors
        spinDriveTrain();
    }

    // spins the left drive train for a distance
    void leftDriveSpinFor(double degrees) {
        leftFrontDrive.spinFor(forward, degrees, turns, false);
        leftBackDrive.spinFor(forward, degrees, turns);
    }

     // spins the left drive train for a distance
    void rightDriveSpinFor(double degrees) {
        rightFrontDrive.spinFor(forward, degrees, turns, false);
        rightBackDrive.spinFor(forward, degrees, turns);
    }

    // destroys the class object
    void destroy() {
        delete this;
    }

  private:
    // define integer values for left and right sticks
    int leftDrive;
    int rightDrive;

    // variables that control the hook
    bool hookUp;
    bool hookDown;

    // spins all drivetrain motors
    void spinDriveTrain() {
        rightFrontDrive.spin(forward);
        rightBackDrive.spin(forward);
        leftFrontDrive.spin(forward);
        leftBackDrive.spin(forward);
    }

    // sets the velocity of the right drive train
    void rightDriveVelocity(double rightDrive) {
        rightFrontDrive.setVelocity(rightDrive, percent);
        rightBackDrive.setVelocity(rightDrive, percent);
    }

    // sets the velocity of the left drive train
    void leftDriveVelocity(double leftDrive) {
        leftFrontDrive.setVelocity(leftDrive, percent);
        leftBackDrive.setVelocity(leftDrive, percent);
    }

    // update the controller values 
    void updateControls(bool driveTrainToggle) {
        // get the current reading from the stick values
        leftDrive = driveTrainToggle ? Controller1.Axis3.position() * 0.75 : Controller1.Axis3.position();
        rightDrive = driveTrainToggle ? Controller1.Axis2.position() * 0.75 : Controller1.Axis2.position();
        // apply them to the current motor velocity
        rightDriveVelocity(rightDrive);
        leftDriveVelocity(leftDrive);
    }
};