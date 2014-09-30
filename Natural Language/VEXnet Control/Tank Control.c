/**************************\
|*  ROBOTC for Beginners  *|
|*  Tank Control          *|
\**************************/

task main()
{
  robotType(recbot);  // Use the default recbot (change this if you use another robot type).

  while(true)         // Loop forever.
  {
    tankControl();    // Use Tank Control.
  }
}
