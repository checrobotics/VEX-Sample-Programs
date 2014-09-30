/**************************\
|*  ROBOTC for Beginners  *|
|*  Release to Start      *|
\**************************/

task main()
{
  robotType(recbot);    // We are using the recbot.

  // Be sure to hold the touch sensor pressed in while starting your program!!

  untilRelease(dgtl6);  // Wait for touch sensor in digital port 6 to be released.

  forward(63);          // Move forward at speed 63.
  wait(1.0);            // Wait 1.0 seconds.
  stop();               // Stop.
}
