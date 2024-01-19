/*
The arm class
This will put all of the control for the arm on controller two
*/
class Arm {

    public:

        // set the stopping values and speeds of all the motors
        Arm() {
            turret.setVelocity(100, percent);
            elbow.setVelocity(35, percent);
            flinger.setVelocity(100, percent);
            lift1.setStopping(hold);
            lift2.setStopping(hold);
        }


        // the main function that handles the arm control
        void manipulatorControl(bool armToggle, bool armHoldToggle,  bool flingerToggle) {
            // make sure the current state of the controller is up to date
            updateControls(armToggle, armHoldToggle);
            // move the motors

            // don't allow drift of the shoulder
            if (absoluteValue(shoulderSpin) >= 10) {
                shoulder.spin(forward);
            } else {
                shoulder.stop();
            }

            // spin the turret
            if (spinTurretLeft) {
                turret.spin(reverse);
            } else if (spinTurretRight) {
                turret.spin(forward);
            } else {
                turret.stop();
            }

            // fling the fling fling
            if (flingerToggle) {
                flinger.spin(forward);
            } else {
                flinger.stop();
            }

            // spins the lift (and the elbow, if legacy mode is enabled)
            if (legacyMode) {
                legacyMotorControl();
            } else {
                primaryMotorControl();
            }
        }


        // destroys the class object
        void destroy() {
            delete this;
        }

    private:

        // this boolean will be set manually in the code to activate and deactivate legacy mode
        bool legacyMode = false;

        // values that spin the turret
        bool spinTurretLeft;
        bool spinTurretRight;

        // the value to articulate the shoulder
        int shoulderSpin;

        // the value to articulate the lift
        int liftSpin;

        // [[LEGACY]] 
        // the value to articulate the elbow
        int elbowSpin;
        // values to articulate the lift in legacy mode
        int legacyLiftUp;
        int legacyLiftDown;

        // update all of the controller values
        void updateControls(bool armToggle, bool armHoldToggle) {
            turret.setStopping(armHoldToggle ? coast : hold);
            shoulder.setStopping(armHoldToggle ? coast : hold);
            // updates the values that will spin the turret
            spinTurretLeft = Controller2.ButtonL2.pressing();
            spinTurretRight = Controller2.ButtonR2.pressing();
            // updates the stick values that will control the arm
            shoulderSpin = armToggle ? Controller2.Axis2.position() / 2 : Controller2.Axis2.position();
            // spins the motors accordingly
            shoulder.setVelocity(shoulderSpin, percent);

            // updates the controls for the lift (and the elbow, if legacy mode is enabled)
            if (legacyMode) {
                legacyControlUpdate(armToggle, armHoldToggle);
            } else {
                primaryControlUpdate();
            }

        }

        // handles the controller updates for the primary configuration of the robot
        void primaryControlUpdate() {
            liftSpin = Controller2.Axis3.position();
            lift1.setVelocity(liftSpin, percent);
            lift2.setVelocity(liftSpin, percent);
        }

        void primaryMotorControl() {
            lift1.spin(forward);
            lift2.spin(forward);
        }


        // return the absolute value of a number
        double absoluteValue(double num) {
            if (num >= 0) {
                return num;
            } else {
                return num * -1;
            }
        }

        // [[LEGACY]]
        // handles controller updates for legacy iderations of the robot
        // i.e. if the elbow apparatus were to be reattached
        void legacyControlUpdate(bool armToggle, bool armHoldToggle) {
            // handles all elbow function control
            elbow.setStopping(armHoldToggle ? coast : hold);
            elbowSpin = armToggle ? Controller2.Axis3.position() / 2 : Controller2.Axis3.position();
            elbow.setVelocity(elbowSpin, percent);

            // updates the values that will actuate the lift
            legacyLiftUp = Controller2.ButtonUp.pressing();
            legacyLiftDown = Controller2.ButtonDown.pressing();
        }

        // handles the motor control for legacy iderations of the robot
        void legacyMotorControl() {
            // legacy lift actuation
            if (legacyLiftUp) {
                lift1.spin(forward);
                lift2.spin(forward);
            } else if (legacyLiftDown) {
                lift1.spin(forward);
                lift2.spin(forward);
            } else {
                lift1.stop();
                lift2.stop();
            }

            // don't allow drift of the elbow
            if (absoluteValue(elbowSpin) >= 10) {
                elbow.spin(forward);
            } else {
                elbow.stop();
            }
        }
};