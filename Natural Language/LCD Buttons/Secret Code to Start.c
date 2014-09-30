/**************************\
|*  ROBOTC for Beginners  *|
|*  Secret Code to Start  *|
\**************************/

task main()
{
  robotType(swervebot);          // We are using the Swervebot.

  // Secret code will be MIDDLE, LEFT, RIGHT:

  stop();                           // Stop.  Do not move.
  untilButtonPress(centerBtnVEX);   // Wait until the CENTER LCD button is pressed.
  untilButtonPress(leftBtnVEX);     // Wait until the LEFT LCD button is pressed.
  untilButtonPress(rightBtnVEX);    // Wait until the RIGHT LCD button is pressed.

  wait(0.5);                        // Wait 0.5 seconds.  (for you to remove your hand)

  forward(63);                      // Move forward at speed 63.
  wait(2.0);                        // Wait 2.0 seconds.
  stop();                           // Stop.
}
