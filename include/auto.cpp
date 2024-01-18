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
            // sets the drive speed to 25%
            setDriveVelocity(25);
            // moves forward 14 inches
            move(14);
            // turns 50 degrees clockwise
            turn(50);
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
        }

        void auto2() {

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

        // turns the turret a specifc degree amount
        void turnTurret(double deg) {
            turret.spinFor(forward, deg, degrees);
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
            turret.setStopping(hold);
            shoulder.setStopping(hold);
            elbow.setStopping(hold);
            lift1.setStopping(hold);
            lift2.setStopping(hold);
        }

        // sets the drivetrain velocity
        void setDriveVelocity(int driveSpeed) {
            leftBackDrive.setVelocity(driveSpeed, percent);
            leftFrontDrive.setVelocity(driveSpeed, percent);
            rightBackDrive.setVelocity(driveSpeed, percent);
            rightFrontDrive.setVelocity(driveSpeed, percent);
            rightTrans.setVelocity(driveSpeed, percent);
            leftTrans.setVelocity(driveSpeed, percent);
        }

        // [[LEGACY]]
        // moves the elbow by a specifc degree amount
        void moveElbow(double deg) {
            elbow.spinFor(forward, deg, degrees);
        }

        //
        // End of auto function definitions
        //
};