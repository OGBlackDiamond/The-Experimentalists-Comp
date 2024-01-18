/*
  The driver class
  All of the control for the driver will be placed on the first controller
*/
class Driver {

  public:

    Driver() {
        leftBackDrive.setStopping(coast);
        leftFrontDrive.setStopping(coast);
        rightBackDrive.setStopping(coast);
        rightFrontDrive.setStopping(coast);
        // rightTrans.setStopping(coast);
        // leftTrans.setStopping(coast);
    }

    // this method will be called in the main method
    void driverControl(bool toggleDriveTrain, bool _transmissionToggle, bool wing1Toggle, bool wing2Toggle) {
        // refresh control stick values
        updateControls(toggleDriveTrain);
        // spin the motors
        spinDriveTrain();
        // set the drivetrain toggle
        transmissionToggle = _transmissionToggle;

        // toggles the wings
        wing1.set(wing1Toggle);
        wing2.set(wing2Toggle);
    }

    // spins the left drive train for a distance
    void leftDriveSpinFor(double degrees) {
        leftFrontDrive.spinFor(forward, degrees, turns, false);
        leftBackDrive.spinFor(forward, degrees, turns, false);
    }

    // spins the left drive train for a distance
    void rightDriveSpinFor(double degrees) {
        rightFrontDrive.spinFor(forward, degrees, turns, false);
        rightBackDrive.spinFor(forward, degrees, turns, true);
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

    // transmission toggle variable
    bool transmissionToggle;

    // spins all drivetrain motors
    void spinDriveTrain() {
        if (transmissionToggle) {
            // rightTrans.spin(forward);
            // leftTrans.spin(forward);
        } else {
            rightFrontDrive.spin(forward);
            rightBackDrive.spin(forward);
            leftFrontDrive.spin(forward);
            leftBackDrive.spin(forward);
        }
    }

    // sets the velocity of the right drive train
    void rightDriveVelocity(double rightDrive) {
        rightFrontDrive.setVelocity(transmissionToggle ? 0 : rightDrive, percent);
        rightBackDrive.setVelocity(transmissionToggle ? 0 : rightDrive, percent);
        // rightTrans.setVelocity(transmissionToggle ? rightDrive : 0, percent);
    }

    // sets the velocity of the left drive train
    void leftDriveVelocity(double leftDrive) {
        leftFrontDrive.setVelocity(transmissionToggle ? 0 : leftDrive, percent);
        leftBackDrive.setVelocity(transmissionToggle ? 0 : leftDrive, percent);
        // leftTrans.setVelocity(transmissionToggle ? leftDrive : 0, percent);
    }

    // update the controller values 
    void updateControls(bool driveTrainToggle) {
        // get the current reading from the stick values
        rightDrive = driveTrainToggle ? Controller1.Axis3.position() * 0.75 : Controller1.Axis3.position();
        leftDrive = driveTrainToggle ? Controller1.Axis2.position() * 0.75 : Controller1.Axis2.position();
        // apply them to the current motor velocity
        rightDriveVelocity(rightDrive);
        leftDriveVelocity(leftDrive);
    }
};