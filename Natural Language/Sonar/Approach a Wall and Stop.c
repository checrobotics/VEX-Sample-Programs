/******************************\
|*  ROBOTC for Beginners      *|
|*  Approach a Wall and Stop  *|
\******************************/

task main()
{
  robotType(recbot);        // We are using the recbot.

  wait(2.0);                // Wait 2.0 seconds to initialize the sonar sensor and position robot.

  forward(63);              // Move forward at speed 63.
  untilSonarLessThan(20);   // Wait until the sonar sees an object 20cm away. (in default sonar ports)
  stop();                   // Stop.
}
