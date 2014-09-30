/**********************************\
|*  ROBOTC for Beginners          *|
|*  Arm Control via Potentiometer *|
\**********************************/

task main()
{
  robotType(recbot);                    // We are using the recbot.

  startMotor(port6, -32);               // Set motor port 6 to speed -32.
  untilPotentiometerLessThan(560);      // Wait until the potentiometer reads a value LESS than 560.
  stopMotor(port6);                     // Stop motor port 6.

  wait(1.0);                            // Wait 1.0 seconds.

  startMotor(port6, 32);                // Set motor port 6 to speed 32.
  untilPotentiometerGreaterThan(1000);  // Wait until the potentiometer reads a value GREATER than 1000.
  stopMotor(port6);                     // Stop motor port 6.
}
