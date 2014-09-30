/**************************\
|*  ROBOTC for Beginners  *|
|*  Forward until Light   *|
\**************************/

task main()
{
  robotType(swervebot);   // We are using the Swervebot.

  forward(63);            // Move forward at speed 63.
  untilLight();           // Wait until the default light sensors see a light line.
  stop();                 // Stop.
}
