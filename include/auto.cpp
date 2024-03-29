/*
    The autonomous class
    This class will contain all functionality related to the autonomous period
*/
class Auto {

    public:
        Auto(Driver _driveTrain) {
            driveTrain = _driveTrain;
        }

        // defines options for autonomous configuration

        // example auto program
        void auto1() {
            flinger.setVelocity(60, percent);
            flinger.spin(forward);
        }

        void auto2() {
            // sets the drive speed to 25%
            setDriveVelocity(25);
            // moves forward 14 inches
            move(14);
            // turns 50 degrees clockwise
            turn(-50);
            // sets the drive speed to 100%
            setDriveVelocity(100);
            // moves forward 13 inches
            move(13);
            // sets the drive speed to 25%
            setDriveVelocity(25);
            // moves backwards 13 inches
            move(-13);
            // set the drive speed to 100%
            setDriveVelocity(100);
            // moves forward 13.5 inches
            move(13.5);
            // sets the drive speed to 25%
            setDriveVelocity(25);
            // moves backward 12 inches
            move(-12);
            // spin 180 degrees
            turn(180);
            // lowers the left wing
            wing2.set(true);
            setDriveVelocity(50);
            // move twelve inches against the bar
            move(12);
            // turn 50 degrees counterclockwise
            turn(50);
            // raise the left wing
            wing2.set(false);
        }

    private:

        Driver driveTrain;

        //
        // The following functions define a set of instructions to make defining an autonomous program easier
        //

        // moves the robot forward. The parameter, distance, is an exact measure of inches.
        void move(double distance) {
            driveTrain.leftDriveSpinFor(distance / 12.25);
            driveTrain.rightDriveSpinFor(distance / 12.25);
        }

        // turns the robot. The parameter is an exact measure of degrees
        void turn(double degrees) {
            driveTrain.leftDriveSpinFor(degrees / 90);
            driveTrain.rightDriveSpinFor((degrees / 90) * -1);
        }

        // turns the shoulder a specific degree amount
        void moveShoulder(double deg) {
            shoulder.spinFor(forward, deg, degrees);
        }

        // lowers or raises the lift a specific degree amount
        void actuateLift(double deg) {
            lift1.spinFor(forward, deg, degrees);
            lift2.spinFor(forward, deg, degrees);
        }

        // sets the motor holding functions
        void setMotorFunctions() {
            shoulder.setStopping(hold);
            lift1.setStopping(hold);
            lift2.setStopping(hold);
        }

        // sets the drivetrain velocity
        void setDriveVelocity(int driveSpeed) {
            
        }

        //
        // End of auto function definitions
        //
};