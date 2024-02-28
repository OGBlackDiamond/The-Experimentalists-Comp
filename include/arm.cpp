/*
The arm class
This will put all of the control for the arm on controller two
*/
class Arm {

    public:

        // set the stopping values and speeds of all the motors
        Arm() {
            flinger.setVelocity(100, percent);
            lift1.setStopping(hold);
            lift2.setStopping(hold);
        }


        // the main function that handles the arm control
        void manipulatorControl(bool armToggle, bool armHoldToggle,  bool flingerToggle, bool wing1Toggle, bool wing2Toggle) {
            // make sure the current state of the controller is up to date
            updateControls(armToggle, armHoldToggle);
            // move the motors

            // don't allow drift of the shoulder
            if (absoluteValue(shoulderSpin) >= 10) {
                shoulder.spin(forward);
            } else {
                shoulder.stop();
            }

            // fling the fling fling
            if (flingerToggle) {
                flinger.spin(forward);
            } else {
                flinger.stop();
            }

            primaryMotorControl();

            // toggles the wings
            wing1.set(wing1Toggle);
            wing2.set(wing2Toggle);
        }


        // destroys the class object
        void destroy() {
            delete this;
        }

    private:

        // the value to articulate the shoulder
        int shoulderSpin;

        // the value to articulate the lift
        int liftSpin;

        // update all of the controller values
        void updateControls(bool armToggle, bool armHoldToggle) {
            shoulder.setStopping(armHoldToggle ? coast : hold);
            // updates the stick values that will control the arm
            shoulderSpin = armToggle ? Controller2.Axis2.position() / 2 : Controller2.Axis2.position();
            // spins the motors accordingly
            shoulder.setVelocity(shoulderSpin, percent);

            primaryControlUpdate();
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
};