/******************************\
|*  ROBOTC for Beginners      *|
|*  Back Away From an Object  *|
\******************************/

task main()
{
  robotType(recbot);          // We are using the recbot.

  wait(2.0);                  // Wait 2.0 seconds to initialize the sonar sensor and position robot (put something in front of it).

  backward(63);               // Back up at speed 63.
  untilSonarGreaterThan(40);  // Wait until the object is 40cm away. (in default sonar ports)
  stop();                     // Stop. Do not move.
}
