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
        void driverControl(bool _driveTrainToggle, bool _transmissionToggle, bool _torqueToggle) {
            // updates the toggle variables
            driveTrainToggle = _driveTrainToggle;
            transmissionToggle = _transmissionToggle;
            torqueToggle = _torqueToggle;

            // refresh control stick values
            updateControls();
            // spin the motors
            spinDriveTrain();
        }

        // spins the left drive train for a distance
        void leftDriveSpinFor(double degrees) {
            leftSun.spinFor(forward, degrees, turns, false);
        }

        // spins the left drive train for a distance
        void rightDriveSpinFor(double degrees) {
            leftSun.spinFor(forward, degrees, turns, false);
        }

        // destroys the class object
        void destroy() {
            delete this;
        }

    private:
        // define integer values for left and right sticks
        int leftDrive;
        int rightDrive;

        // define torque toggle 
        bool torqueToggle = false;

        // define toggles
        bool driveTrainToggle = false;
        bool transmissionToggle = true;

        // spins all drivetrain motors
        void spinDriveTrain() {
            // applies set speeds to the transmission motors
            rightRing.spin(forward);
            leftRing.spin(forward);
            rightSun.spin(forward);
            leftSun.spin(forward);
        }

        // update the controller values 
        void updateControls() {
            // get the current reading from the stick values
            rightDrive = driveTrainToggle ? Controller1.Axis3.position() * 0.75 : Controller1.Axis3.position();
            leftDrive = driveTrainToggle ? Controller1.Axis2.position() * 0.75 : Controller1.Axis2.position();
            // apply them to the current motor velocity
            rightDriveVelocity();
            leftDriveVelocity();
        }

        // sets the velocity of the right drive train
        void rightDriveVelocity() {
            if (transmissionToggle) {
                rightAutomatic();
            } else {
                rightManual();
            }
        }

        // sets the velocity of the left drive train
        void leftDriveVelocity() {
            if (transmissionToggle) {
                leftAutomatic();
            } else {
                leftManual();
            }
        }

        void rightAutomatic() {
            double rightSunVelocity = rightSun.velocity(percent);
            double rightSunCurrent = rightSun.current(percent);

            if (rightSunCurrent > 80 && rightSunVelocity < 20) {
                rightRingSpeed = 0;
            } else {
                rightRingSpeed = rightSunCurrent;
            }

            rightSun.setVelocity(rightDrive, percent);
            rightRing.setVelocity(rightRingSpeed, percent);
        }

        void leftAutomatic() {
            double leftSunVelocity = leftSun.velocity(percent);
            double leftSunCurrent = leftSun.current(percent);

            if (leftSunCurrent > 80 && leftSunVelocity < 20) {
                leftRingSpeed = 0;
            } else {
                leftRingSpeed = leftSunCurrent;
            }

            leftSun.setVelocity(leftDrive, percent);
            leftRing.setVelocity(leftRingSpeed, percent);
        }


        void rightManual() {
            rightSun.setVelocity(rightDrive);
            if (torqueToggle) {
                rightRing.setVelocity(0, percent);
            } else {
                rightRing.setVelocity(rightDrive, percent);
            }

        }

        void leftManual() {
            leftSun.setVelocity(leftDrive);
            if (torqueToggle) {
                leftRing.setVelocity(0, percent);
            } else {
                leftRing.setVelocity(leftDrive, percent);
            }
        }
        // takes the absolute value of a number
        double absoluteValue(double num) {
            return num >= 0 ? 0 : num * -1;
        }
};