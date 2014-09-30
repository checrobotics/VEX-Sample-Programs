void testUByteSByteAssignment()
{
  const int kGrowth = 16;
  unsigned char uChar[256 / kGrowth];
  signed char sChar[256 / kGrowth];
  for (int i = 0; i < (256 / kGrowth); ++i)
  {
    uChar[i] = i * kGrowth;
    sChar[i] = i * kGrowth;
  }

  int nErrorCount = 0;
  for (int i = 0; i < (256 / kGrowth); ++i)
  {
    int nTemp;
    int nUnsigned = i * kGrowth;
    int nSigned = (i < (128 / kGrowth)) ? nUnsigned : (nUnsigned - 256);

    if (uChar[i] != nUnsigned)
      ++nErrorCount;
    if (sChar[i] != nSigned)
      ++nErrorCount;

    // Verify retrieval from 'char' array and assignment to 'short'
    nTemp = uChar[i];
    if (nTemp != nUnsigned)
      ++nErrorCount;
    nTemp = sChar[i];
    if (nTemp != nSigned)
      ++nErrorCount;
  }
  if (nErrorCount == 0)
    writeDebugStreamLine("'testUByteSByteAssignment' passed.");
  else
  {
    writeDebugStreamLine("'testUByteSByteAssignment' FAILED.");
  }
}

task main()
{
  clearDebugStream();
  testUByteSByteAssignment();
}
