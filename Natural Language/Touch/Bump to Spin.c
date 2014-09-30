/**************************\
|*  ROBOTC for Beginners  *|
|*  Bump to Spin          *|
\**************************/

task main()
{
  robotType(recbot);        // We are using the recbot.

  while(true)
  {
    stop();                 // Stop. Do not move.
    untilBump(dgtl6);       // Wait for touch sensor in digital port 6 to be bumped.
    pointTurn(right, 95);   // Make a right turn in place at speed 95.
    wait(1.5);              // Wait for 1.5 seconds.
  }
}
