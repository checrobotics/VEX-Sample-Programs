#pragma config(Motor,  port2,           frontRightMotor, tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port3,           backRightMotor, tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port4,           frontLeftMotor, tmotorNormal, openLoop)
#pragma config(Motor,  port5,           backLeftMotor, tmotorNormal, openLoop)

task main()
{
	wait1Msec(2000);
	// Move forward at full power for 3 seconds
	motor[frontRightMotor] = 127;		  // Motor on port2 is run at full (127) power forward
	motor[backRightMotor]  = 127;		  // Motor on port3 is run at full (127) power forward
	motor[frontLeftMotor] = 127;		  // Motor on port4 is run at full (127) power forward
	motor[backLeftMotor]  = 127;		  // Motor on port5 is run at full (127) power forward
	wait1Msec(3000);			          
}												           


