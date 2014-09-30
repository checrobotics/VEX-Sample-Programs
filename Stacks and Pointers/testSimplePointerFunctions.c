//#include <stdio.h>
//#include <stdlib.h>
#pragma noProlog
#define printf writeDebugStream

void testSimplePointerFunctions()
{
	char	cChar;
	short nShort;
	long	nLong;
	int j;

	char	*pChar			= &cChar;
	short *pShort			= &nShort;
	long	*pLong			= &nLong;

	*pChar	= 'A';													VERIFY(cChar  == 'A');
	*pShort = 1234;													VERIFY(nShort == 1234);
	*pLong	= 56789;												VERIFY(nLong  == 56789);

	pChar[0]	= 'B';												VERIFY(cChar  == 'B');
	pShort[0] = 987;												VERIFY(nShort == 987);
	pLong[0]	= 12345;											VERIFY(nLong  == 12345);

	for (int i = 0; i < 5; ++i)
	{
		*pChar	= i;													VERIFY(cChar  == i);
		*pShort = i;													VERIFY(nShort == i);
		*pLong	= i;													VERIFY(nLong  == i);

		pChar[0]	= i + 3;										VERIFY(cChar  == i + 3);
		pShort[0] = i + 3;										VERIFY(nShort == i + 3);
		pLong[0]	= i + 3;										VERIFY(nLong  == i + 3);
	}

	for (long i = 0; i < 5; ++i)
	{
		*pChar	= i + 4;											VERIFY(cChar  == i + 4);
		*pShort = i + 4;											VERIFY(nShort == i + 4);
		*pLong	= i + 4;											VERIFY(nLong  == i + 4);

		pChar[0]	= i;												VERIFY(cChar  == i);
		pShort[0] = i;												VERIFY(nShort == i);
		pLong[0]	= i;												VERIFY(nLong  == i);
	}

	if (j == 0)
	{
		pChar[j]	= 'A';												VERIFY(cChar  == 'A');
		pShort[j] = 1234;												VERIFY(nShort == 1234);
		pLong[j]	= 56789;											VERIFY(nLong  == 56789);
	}
}

void testPointerDereference()
{
  int AValue, BValue;
  int *testPointer;
  typedef struct
  {
    int nDummy;
    int nResult;
    long nDummy2;
    long *pLong;
  } TStruct;
  TStruct *pStruct;
  long j;
  TStruct nStruct[5];

  testSimplePointerFunctions();
  memset(&nStruct, 0, sizeof(nStruct));
  pStruct = &nStruct[0];
  pStruct = &nStruct[3];
  for (j = 0; j < 3; ++j)
  {
    //pStruct = &(nStruct[j].nResult);        // Should be a compiler error
    pStruct = &nStruct[j];
    testPointer = &nStruct[j].nResult;
    //testPointer = &pStruct.nResult;
    testPointer = &pStruct->nResult;
	  *testPointer = j + 3;
	  VERIFY(nStruct[j].nResult == j + 3);

	  pStruct->pLong = &pStruct->nDummy2;
	  *pStruct->pLong = 505;

    pStruct = &nStruct[j];
    testPointer = &pStruct->nResult;
	  *testPointer = j + 30;
	  VERIFY(nStruct[j].nResult == j + 30);
  }

	printf("\"AValue\": %4d; BValue: %4d\n", AValue, BValue);
}

task main()
{
  clearDebugStream();
  while (true)
  {
    testPointerDereference();
	  writeDebugStreamLine("'*' (Pointer Dereference) passed");
	  wait1Msec(100);
	}
}
