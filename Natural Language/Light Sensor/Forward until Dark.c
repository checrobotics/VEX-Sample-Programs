/**************************\
|*  ROBOTC for Beginners  *|
|*  Forward until Dark    *|
\**************************/

task main()
{
  robotType(swervebot);   // We are using the Swervebot.

  forward(63);            // Move forward at speed 63.
  untilDark();            // Wait until the default light sensors see a dark line.
  stop();                 // Stop.
}
