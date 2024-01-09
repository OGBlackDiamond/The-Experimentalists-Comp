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
            turn(360);
            move(360);
        }

        void auto2() {

        }

    private:

        Driver driveTrain;

        //
        // The following functions define a set of instructions to make defining an autonomous program easier
        //

        void move(double distance) {
            //driveTrain.leftDriveSpinFor(distance);
            driveTrain.rightDriveSpinFor(distance);
        }

        void turn(double degrees) {
            driveTrain.leftDriveSpinFor(degrees);
            driveTrain.rightDriveSpinFor(degrees * -1);
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

        //
        // End of auto function definitions
        //
};