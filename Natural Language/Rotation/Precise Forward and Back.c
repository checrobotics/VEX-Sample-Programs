/******************************\
|*  ROBOTC for Beginners      *|
|*  Precise Forward and Back  *|
\******************************/

task main()
{
  robotType(recbot);          // We are using the Recbot.

  forward(63);                // Move forward at speed 63.
  untilRotations(2.0);        // Wait until the wheels have rotated 2.0 times
  stop();                     // Stop.

  wait(0.5);                  // Wait 0.5 seconds.

  backward(63);               // Move backward at speed 63.
  untilEncoderCounts(720);    // Wait until the encoders count 720 times (360 = 1 rotation).
  stop();                     // Stop.

  // The robot should end up in the original position as 720 encoder counts is equal to 2.0 rotations.
}
