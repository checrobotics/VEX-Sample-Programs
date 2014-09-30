#pragma debuggerWindows(debugStream)


void testPointerOperatorWithNULL()
{
	typedef struct TStruct
	{
		short  nFirst;
		long  nSecond;
		short  nThird;
	} TStruct;

	int nOffset1 = 999;
	int nOffset2 = 999;
	int nOffset3 = 999;
	int nOffset4 = 999;
	int nOffset5 = 999;
	int nOffset6 = 999;

	nOffset1 = (int) &(((TStruct *) NULL)->nFirst);			VERIFY(nOffset1 == 0);
	nOffset2 = (int) &((TStruct *) NULL)->nSecond;			VERIFY(nOffset2 == 4);
	nOffset3 = (int) &((TStruct *) NULL)->nThird;				VERIFY(nOffset3 == 8);

	nOffset4 = (int) &((TStruct *) 100)->nFirst;				VERIFY(nOffset4 == 100);
	nOffset5 = (int) &((TStruct *) 100)->nSecond;				VERIFY(nOffset5 == 104);
	nOffset6 = (int) &((TStruct *) 100)->nThird;				VERIFY(nOffset6 == 108);
	return;
}


void testPeriodOperatorWithNULL()
{
	typedef struct TStruct
	{
		int  nFirst;
		int  nSecond;
		int  nThird;
	} TStruct;

	int nOffset1 = 777;
	int nOffset2 = 777;
	int nOffset3 = 777;
	int nOffset4 = 777;
	int nOffset5 = 777;
	int nOffset6 = 777;

	nOffset1 = (int) &(((TStruct) NULL).nFirst);			VERIFY(nOffset1 == 0);
	nOffset2 = (int) &(((TStruct) NULL).nSecond);			VERIFY(nOffset2 == 4);
	nOffset3 = (int) &((TStruct) NULL).nThird;				VERIFY(nOffset3 == 8);

	nOffset4 = (int) &((*((TStruct *) 100)).nFirst);	VERIFY(nOffset4 == 100);
	nOffset5 = (int) &(*(TStruct *) 100).nSecond;			VERIFY(nOffset5 == 104);
	nOffset6 = (int) &(*(TStruct *) 100).nThird;			VERIFY(nOffset6 == 108);
	return;
}

task main()
{
	clearDebugStream();
	writeDebugStreamLine("Starting 'NULL' operator test....");

	testPointerOperatorWithNULL();
	testPeriodOperatorWithNULL();

	writeDebugStreamLine("'NULL' operator test...PASSED");
}
