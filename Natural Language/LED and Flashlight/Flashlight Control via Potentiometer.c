/******************************************\
|*  ROBOTC for Beginners                  *|
|*  Flashlight Control via Potentiometer  *|
\******************************************/

task main()
{
  robotType(swervebot);
  int brightness = 0;

  while(true)                             // Loop Forever
  {
    brightness = SensorValue[in6] / 32;   // Set 'brightness' to the current sensor reading on in6 (potentiometer) / 32 for scaling.
    turnFlashlightOn(port4, brightness);  // Turn the flashlight in port4 ON at brightness of 'brightness'.
  }
}

/*
  Set the power of the flashlight equal to a scaled value from the potentiometer
  Divide by 32 on the Cortex, since the potentiometer values are 0 - 4095
  Divide by 8 on the PIC, since the potentiometer values are 0 - 1023
*/
