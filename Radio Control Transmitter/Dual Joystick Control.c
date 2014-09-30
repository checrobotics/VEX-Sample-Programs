/*************************************************************************
VEX - Dual Joystick Control

Description: This program allows the user to remotely control their robot
using the vertical axis of the Radio Control Transmitter. An infinite
while loop is used to continually update the power level of the motor
ports to the values provided by the transmitter.

Configuration: This program is written to work with the Squarebot model.
	Right Motor - port2
	Left	Motor - port3
	RF Receiver - Rx1

Additional Notes:
-	The "bMotorReflected[port2] = 1;" is needed with the Squarebot model,
	but may not be needed for all robot configurations.
-	Each motor is controlled by a separate joystick on the transmitter.
-	The "bVexAutonomousMode = false;" is needed to open up communication so
	that the VEX can receive signals.
-	Parameters and information for vexRT:
		Ch1 = Right Joystick X-axis
			Full Right = 127
			Middle     = 0
			Full Left  = -127
		Ch2 = Right Joystick Y-axis
			Full Up    = 127
			Middle     = 0
			Full Down  = -127
		Ch3 = Left Joystick Y-axis
			Full Up    = 127
			Middle     = 0
			Full Down  = -127
		Ch4 = Left Joystick X-axis
			Full Right = 127
			Middle     = 0
			Full Left  = -127
		Ch5 = Rear Left Buttons
			None Pressed    = 0
			Top Pressed     = 127
			Down Pressed  	= -127
			Both Pressed		= 0
		Ch6 = Rear Right Buttons
			None Pressed    = 0
			Top Pressed     = 127
			Down Pressed  	= -127
			Both Pressed		= 0
*************************************************************************/

task main()
{
	bMotorFlippedMode[port2] = true; 	//Port 2 Motor Direction Flipped


	while (1 == 1)									  //Creates and infinite loop
	{
		motor[port2] = vexRT(Ch2);		  //The right motor is set to equal the value transmitted by Ch2 (y-axis of the right joystick)
		motor[port3] = vexRT(Ch3);		  //The left motor is set to equal the value transmitted by Ch3 (y-axis of the left joystick)
	}

}
