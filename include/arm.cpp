/*
The arm class
This will put all of the control for the arm on controller two
*/
class Arm {

    public:

        // set the stopping values and speeds of all the motors
        Arm() {
            turret.setVelocity(100, percent);
            flinger.setVelocity(100, percent);
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

            // don't allow drift of the shoulder
            if (absoluteValue(elbowSpin) >= 10) {
                elbow.spin(forward);
            } else {
                elbow.stop();
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
        }



        // destroys the class object
        void destroy() {
            delete this;
        }

    private:

        // variables that spin the turret
        bool spinTurretLeft;
        bool spinTurretRight;

        // the value to articulate the shoulder
        int shoulderSpin;

        // the value to articulate the elbow
        int elbowSpin;

        // update all of the controller values
        void updateControls(bool armToggle, bool armHoldToggle) {
            turret.setStopping(armHoldToggle ? coast : hold);
            shoulder.setStopping(armHoldToggle ? coast : hold);
            elbow.setStopping(armHoldToggle ? coast : hold);
            // updates the values that will spin the turret
            spinTurretLeft = Controller2.ButtonL2.pressing();
            spinTurretRight = Controller2.ButtonR2.pressing();
            // updates the stick values that will control the arm
            elbowSpin = armToggle ? Controller2.Axis3.position() / 2 : Controller2.Axis3.position();
            shoulderSpin = armToggle ? Controller2.Axis2.position() / 2 : Controller2.Axis2.position();
            // spins the motors accordingly
            elbow.setVelocity(elbowSpin, percent);
            shoulder.setVelocity(shoulderSpin, percent);
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