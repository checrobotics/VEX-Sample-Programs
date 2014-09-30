/******************************\
|*  ROBOTC for Beginners      *|
|*  Open and close the claw.  *|
\******************************/

task main()
{
  // Open claw:
  startMotor(port10, 127);      // start motor on port 10 at full speed
  wait(0.6);                    // wait 0.6 seconds
  stopMotor(port10);            // stop motor on port 10 (avoid stalling the motors)

  // Go foward:
  forward();                    // move forward
  wait(2.0);                    // wait 2.0 seconds
  stop();                       // stop

  // Close claw:
  startMotor(port10, -127);     // start motor on port 10 at full speed backward
  wait(0.6);                    // wait 0.6 seconds
  stopMotor(port10);            // stop motor on port 10 (avoid stalling the motors)

  // Backup with prize in hand:
  backward();                   // move backward
  wait(2.0);                    // wait 2.0 seconds
  stop();                       // stop
}
