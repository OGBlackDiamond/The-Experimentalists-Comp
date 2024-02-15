/*
  The driver class
  All of the control for the driver will be placed on the first controller
*/
class Driver {


    // TRANSMISSION CONROL REFERENCE //

    // torque: sun gear full, ring gear stop
    // 2/3: both full - opposite direction
    // speed: both full

    public:

        Driver() {
            // sets the ring gear for each transmission to hold its position when stopped
            rightRing.setStopping(hold);
            leftRing.setStopping(hold);
        }

        // this method will be called in the main method
        void driverControl(bool toggleDriveTrain,  bool wing1Toggle, bool wing2Toggle) {
            // refresh control stick values
            updateControls(toggleDriveTrain);
            // spin the motors
            spinDriveTrain();

            // toggles the wings
            wing1.set(wing1Toggle);
            wing2.set(wing2Toggle);
        }

        // spins the left drive train for a distance
        void leftDriveSpinFor(double degrees) {
            
        }

        // spins the left drive train for a distance
        void rightDriveSpinFor(double degrees) {
            
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

        }

        // sets the velocity of the right drive train
        void rightDriveVelocity(double rightDrive) {
            rightSun = rightDrive;
            rightRing = (rightSun.current(percent) / rightSun.velocity(percent)) * rightDrive;
        }

        // sets the velocity of the left drive train
        void leftDriveVelocity(double leftDrive) {
            leftSun = leftDrive;
            leftRing = (leftSun.current(percent) / leftSun.velocity(percent)) * leftDrive;
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

        // takes the absolute value of a number
        double absoluteValue(double num) {
            return num >= 0 ? 0 : num * -1;
        }
};