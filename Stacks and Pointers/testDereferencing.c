#pragma debuggerWindows(debugStream)


task main()
{
	int **ppInt;
	int *pInt;
	int Int;

	clearDebugStream();
	writeDebugStreamLine("Start Testing 'deferencing...");

	pInt = &Int;
	ppInt = &pInt;

	**ppInt = 67;
	VERIFY (Int == 67);
	*pInt = 69;
	VERIFY(Int == 69);

	writeDebugStreamLine("....Testing 'deferencing PASSED");
}
