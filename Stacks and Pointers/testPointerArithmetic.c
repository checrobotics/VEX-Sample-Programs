#pragma debuggerWindows(debugStream)


task main()
{
	char cChar;
	short nShort;
	long nLong;
	long nOldValue;
	long nNewValue;

	char 	*pCharPointer 	= &cChar;
	short *pShortPointer	= &nShort;
	long 	*pLongPointer		= &nLong;

	clearDebugStream();
	writeDebugStreamLine("Starting test of pointer arithmetic....");

	nOldValue = (long) pCharPointer;
	pCharPointer += 2;
	nNewValue = (long) pCharPointer;
	VERIFY((nNewValue - nOldValue) == (2 * sizeof(char)));

	nOldValue = (long) pShortPointer;
	pShortPointer += 2;
	nNewValue = (long) pShortPointer;
	VERIFY((nNewValue - nOldValue) == (2 * sizeof(short)));

	nOldValue = (long) pLongPointer;
	pLongPointer += 2;
	nNewValue = (long) pLongPointer;
	VERIFY((nNewValue - nOldValue) == (2 * sizeof(long)));

	writeDebugStreamLine("Pointer arithmetic test PASSED");
}
