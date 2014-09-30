/********************************\
|*  ROBOTC for Beginners        *|
|*  Moving Forward and Backward *|
\********************************/

task main()
{
  robotType(recbot);  // We are using the recbot.

  forward(63);        // Move forward at speed 63.
  wait(2.0);          // Wait 2.0 seconds.
  stop();             // Stop the robot.
  wait();             // Wait for 1.0 seconds.

  backward(63);       // Move backward at speed 63.
  wait(2.0);          // Wait 2.0 seconds.
  stop();             // Stop the robot.
  wait();             // Wait for 1.0 seconds.
}
