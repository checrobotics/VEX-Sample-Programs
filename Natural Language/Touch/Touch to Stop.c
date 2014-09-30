/**************************\
|*  ROBOTC for Beginners  *|
|*  Touch to Stop         *|
\**************************/

task main()
{
  robotType(recbot);    // We are using the recbot.

  forward(63);          // Move forward at speed 63.
  untilTouch(dgtl6);    // Wait for touch sensor in digital port 6 to be pressed.
  stop();               // Stop.
}
