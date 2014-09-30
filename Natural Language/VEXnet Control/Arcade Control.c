/**************************\
|*  ROBOTC for Beginners  *|
|*  Arcade Control        *|
\**************************/

task main()
{
  robotType(recbot);  // Use the default recbot (change this if you use another robot type).

  while(true)         // Loop forever.
  {
    arcadeControl();  // Use Tank Control.
  }
}
