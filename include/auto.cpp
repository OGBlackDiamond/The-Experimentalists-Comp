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

        void auto1() {
            setDriveVelocity(25);
            move(14);
            turn(50);
            setDriveVelocity(100);
            move(13);
            setDriveVelocity(25);
            move(-13);
            setDriveVelocity(100);
            move(13.5);
            setDriveVelocity(25);
            move(-12);
        }

        void auto2() {

        }

    private:

        Driver driveTrain;

        //
        // The following functions define a set of instructions to make defining an autonomous program easier
        //

        void move(double distance) {
            driveTrain.leftDriveSpinFor(distance / 12.25);
            driveTrain.rightDriveSpinFor(distance / 12.25);
        }

        void turn(double degrees) {
            driveTrain.leftDriveSpinFor(degrees / 90);
            driveTrain.rightDriveSpinFor((degrees / 90) * -1);
        }

        void turnTurret(double deg) {
            turret.spinFor(forward, deg, degrees);
        }

        void moveShoulder(double deg) {
            shoulder.spinFor(forward, deg, degrees);
        }

        void moveElbow(double deg) {
            elbow.spinFor(forward, deg, degrees);
        }

        void setMotorFunctions() {
            turret.setStopping(hold);
            shoulder.setStopping(hold);
            elbow.setStopping(hold);
        }

        void setDriveVelocity(int driveSpeed) {
            leftBackDrive.setVelocity(driveSpeed, percent);
            leftFrontDrive.setVelocity(driveSpeed, percent);
            rightBackDrive.setVelocity(driveSpeed, percent);
            rightFrontDrive.setVelocity(driveSpeed, percent);
        }

        //
        // End of auto function definitions
        //
};