//////////////////////////////////////////////////////////////////////////////////////////////////
//
//			Program to test intrinsic variables related to Watchdog Timer on VEX Cortex
//
/////////////////////////////////////////////////////////////////////////////////////////////////

static bool bWatchdogReset;
static int  nWatchdogInterval;

task main()
{
	while (true)
	{
		bWatchdogReset = bResetFromWatchdogTimeout;
		nWatchdogInterval = nWatchdogTimeoutInterval;
		wait1Msec(10);
	}
	return;
}
