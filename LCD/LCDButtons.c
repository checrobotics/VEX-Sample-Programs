
/**************************/
/* Possible combinations: */
/*                        */
/* Binary   Decimal   Btn */
/**************************/
/* 000        0       --- */
/* 001        1       L-- */
/* 010        2       -C- */
/* 011        3       LC- */
/* 100        4       --R */
/* 101        5       L-R */
/* 110        6       -CR */
/* 111        7       LCR */
/**************************/

task main()
{
  while(true)
  {
    // Clear LCD Lines
    clearLCDLine(0);
    clearLCDLine(1);

    // Top LCD Line Display Stuff:
    displayLCDPos(0,0);
    displayNextLCDString("nLCDButtons");
    displayNextLCDChar(' ');
    displayNextLCDChar('=');
    displayNextLCDChar(' ');
    displayNextLCDNumber(nLCDButtons);      // 'nLCDButtons' is the SUM of the LCD button values.

    // Bottom LCD Line Display Stuff:
    displayLCDPos(1,0);
    displayNextLCDChar('L');
    displayLCDPos(1,2);
    displayNextLCDNumber(kButtonLeft);      // 'kButtonLeft' is worth decimal 1, binary 0001, or 2^0.

    displayLCDPos(1,6);
    displayNextLCDChar('C');
    displayLCDPos(1,8);
    displayNextLCDNumber(kButtonCenter);    // 'kButtonCenter' is worth decimal 2, binary 0010, or 2^1.

    displayLCDPos(1,13);
    displayNextLCDChar('R');
    displayLCDPos(1,15);
    displayNextLCDNumber(kButtonRight);     // 'kButtonRight' is worth decimal 4, binary 0100, or 2^2.


    // Wait a little to keep the screen refreshing smoothly:
    wait1Msec(250);
  }
}
