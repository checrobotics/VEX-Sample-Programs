void testPointer(const char *pCharBuff, const short *pShortBuff, const long *pLongBuff, int nBufferSize)
{
	ubyte aChar;
	short aShort;
	long aLong;
	int i;
	int nCalculations;

	aChar = 67 + *pCharBuff + 5;
	aChar = *pCharBuff;
	aChar = pCharBuff[0];
	aChar = pCharBuff[1];
	aChar = pCharBuff[2];
	aChar = pCharBuff[3];
	aChar = pCharBuff[4];
	aChar = pCharBuff[300];
	aChar = pCharBuff[i];
	aChar = pShortBuff[i];
	aChar = pLongBuff[i];

	aShort = 67 + *pShortBuff + 5;
	aShort = *pShortBuff;
	aShort = pShortBuff[0];
	aShort = pShortBuff[1];
	aShort = pShortBuff[2];
	aShort = pShortBuff[3];
	aShort = pShortBuff[4];
	aShort = pShortBuff[300];
	aShort = pCharBuff[i];
	aShort = pShortBuff[i];
	aShort = pLongBuff[i];

	aLong = 67 + *pLongBuff + 5;
	aLong = *pLongBuff;
	aLong = pLongBuff[0];
	aLong = pLongBuff[1];
	aLong = pLongBuff[2];
	aLong = pLongBuff[3];
	aLong = pLongBuff[4];
	aLong = pLongBuff[300];
	aLong = pCharBuff[i];
	aLong = pShortBuff[i];
	aLong = pLongBuff[i];


	aChar = 65 + pCharBuff[4];
	aChar = 25000 + pCharBuff[4];
	aChar = 68976 + pCharBuff[4]; // 'long' constant
	nCalculations = pCharBuff[4] + pCharBuff[5] + pCharBuff[6];
	aChar = 'b';
	for (int i = 0; i < nBufferSize; ++i)
	{
	  aChar = pCharBuff[i];
	}
}


task main()
{
  ubyte chars[10];
  short words[10];
  long longs[10];
  int ii;
  int jj = rand();

  testPointer(&chars, &words, &longs, sizeof(chars));
  testPointer(&chars[3], &words[4], &longs[5], sizeof(chars));
  for (ii = 0; ii < 5; ++ii)
  {
    chars[ii] = jj;
    words[ii] = jj;
    longs[ii] = jj;
    testPointer(&chars[ii], &words[ii + 4], &longs[ii + 6], sizeof(chars));
    jj = chars[ii];
    jj = words[ii];
    jj = longs[ii];
  }
  //testPointer("ABCDEFGHI", 10);
}
