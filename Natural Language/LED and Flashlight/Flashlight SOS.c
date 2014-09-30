/**************************\
|*  ROBOTC for Beginners  *|
|*  Flashlight SOS        *|
\**************************/

task main()
{
  robotType(recbot);      // We will use the recbot's default setup (attach a flashlight to the recbot on motor-port 4)

  while(true)             // Loop forever (we want our SOS to be seen!)
  {
    // S (...):
    turnFlashlightOn();   // Turn the Flashlight ON.
    wait(0.2);            // Wait 0.2 seconds.
    turnFlashlightOff();  // Turn the Flashlight OFF.
    wait(0.2);            // Wait 0.2 seconds.

    turnFlashlightOn();   // Turn the Flashlight ON.
    wait(0.2);            // Wait 0.2 seconds.
    turnFlashlightOff();  // Turn the Flashlight OFF.
    wait(0.2);            // Wait 0.2 seconds.

    turnFlashlightOn();   // Turn the Flashlight ON.
    wait(0.2);            // Wait 0.2 seconds.
    turnFlashlightOff();  // Turn the Flashlight OFF.
    wait(0.5);            // Wait 0.5 seconds.

    // O (---):
    turnFlashlightOn();   // Turn the Flashlight ON.
    wait(0.5);            // Wait 0.5 seconds.
    turnFlashlightOff();  // Turn the Flashlight OFF.
    wait(0.5);            // Wait 0.5 seconds.

    turnFlashlightOn();   // Turn the Flashlight ON.
    wait(0.5);            // Wait 0.5 seconds.
    turnFlashlightOff();  // Turn the Flashlight OFF.
    wait(0.5);            // Wait 0.5 seconds.

    turnFlashlightOn();   // Turn the Flashlight ON.
    wait(0.5);            // Wait 0.5 seconds.
    turnFlashlightOff();  // Turn the Flashlight OFF.
    wait(0.5);            // Wait 0.5 seconds.

    // S (...):
    turnFlashlightOn();   // Turn the Flashlight ON.
    wait(0.2);            // Wait 0.2 seconds.
    turnFlashlightOff();  // Turn the Flashlight OFF.
    wait(0.2);            // Wait 0.2 seconds.

    turnFlashlightOn();   // Turn the Flashlight ON.
    wait(0.2);            // Wait 0.2 seconds.
    turnFlashlightOff();  // Turn the Flashlight OFF.
    wait(0.2);            // Wait 0.2 seconds.

    turnFlashlightOn();   // Turn the Flashlight ON.
    wait(0.2);            // Wait 0.2 seconds.
    turnFlashlightOff();  // Turn the Flashlight OFF.
    wait(0.2);            // Wait 0.2 seconds.

    wait(2.0);            // Wait 2.0 seconds before restarting loop.
  }
}
