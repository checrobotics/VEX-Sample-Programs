#pragma debuggerWindows(debugStream)

void viaReferenceVariables(char &cChar, short &nShort, long &nLong)
{
	char 	*pCharPointer 	= &cChar;
	short *pShortPointer	= &nShort;
	long 	*pLongPointer		= &nLong;

	long nOldValue;
	long nNewValue;

	nOldValue = (long) pCharPointer;
	pCharPointer++;
	++pCharPointer;
	nNewValue = (long) pCharPointer;
	VERIFY((nNewValue - nOldValue) == (2 * sizeof(char)));

	nOldValue = (long) pShortPointer;
	pShortPointer++;
	++pShortPointer;
	nNewValue = (long) pShortPointer;
	VERIFY((nNewValue - nOldValue) == (2 * sizeof(short)));

	nOldValue = (long) pLongPointer;
	pLongPointer++;
	++pLongPointer;
	nNewValue = (long) pLongPointer;
	VERIFY((nNewValue - nOldValue) == (2 * sizeof(long)));
}


task main()
{
	char cChar 			= 11;
	short nShort		= 12;
	long nLong			= 13;
	long nOldValue;
	long nNewValue;

	char 	*pCharPointer 	= &cChar;
	short *pShortPointer	= &nShort;
	long 	*pLongPointer		= &nLong;

	clearDebugStream();
	writeDebugStreamLine("Starting test of '++' and '--' operands....");

	nOldValue = (long) pCharPointer;
	pCharPointer++;
	++pCharPointer;
	nNewValue = (long) pCharPointer;
	VERIFY((nNewValue - nOldValue) == (2 * sizeof(char)));

	nOldValue = (long) pShortPointer;
	pShortPointer++;
	++pShortPointer;
	nNewValue = (long) pShortPointer;
	VERIFY((nNewValue - nOldValue) == (2 * sizeof(short)));

	nOldValue = (long) pLongPointer;
	pLongPointer++;
	++pLongPointer;
	nNewValue = (long) pLongPointer;
	VERIFY((nNewValue - nOldValue) == (2 * sizeof(long)));

	viaReferenceVariables(cChar, nShort, nLong);
	writeDebugStreamLine("Testing passed '++' /--' operands");
}
