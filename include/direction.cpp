/*
    The gyro class
    This class will contain all functionality related to the gyroscope
*/
class Direction {

  public:

    Direction() {}

    // should be called alongside 
    void accountForSpin() {
      updateRotation();
      spinTurret();
    }


    private:

        double relativeSpin = 0;
        double previousRelativeSpin;

        // updates the rotational value of the gyro
        void updateRotation() {
            previousRelativeSpin = relativeSpin;
            relativeSpin = dir.heading(degrees);
        }

        // spins the turret a specified ammount based on the gyro value
        void spinTurret() {
            turret.spinFor(forward, gyroOverflow(), degrees);
        }

        // calibrates the gyro
        void calibrate() {
            dir.calibrate();
            wait(2, seconds);
        }

        // calculates the rotation the turret needs to take
        //also calculates the rollover in the motor encoders
        double gyroOverflow() {
            // calculates the ammount the motor needs to spin
            double rotationValue = relativeSpin - previousRelativeSpin;

            // accounts for the rollover between 359 and 0 on the motor encoder
            if (rotationValue > 180) {
                rotationValue = rotationValue - 360;
            } else if (rotationValue < -180) {
                rotationValue = 360 + rotationValue;
            }

            return rotationValue;
        }
};