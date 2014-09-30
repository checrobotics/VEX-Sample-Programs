/**************************\
|*  ROBOTC for Beginners  *|
|*  Perfect Right Turn    *|
\**************************/

task main()
{
  robotType(recbot);      // We are using the Recbot.

  pointTurn(right);       // Make a right turn in place.
  untilRotations(1.1);    // Wait until the wheels have rotated 1.1 times
  stop();                 // Stop.
}
