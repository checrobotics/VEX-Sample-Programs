/******************************\
|*  ROBOTC for Beginners      *|
|*  Line Track for Rotations  *|
\******************************/

task main()
{
  robotType(swervebot);         // We are using the Swervebot.

  lineTrackForRotations(3.75);  // Track a line for 3.75 rotations of the wheels.
  stop();                       // Stop.
}
