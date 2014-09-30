//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                         Test 'sscanf' Implementation
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma noProlog
#pragma debuggerWindows(debugStream)

void test_atoi()
{
  short nShort;
  long  nLong;
  string sTemp = "5876ABC";

  nShort = atoi(sTemp);
  VERIFY(nShort == 5876);

  nLong = atoi(sTemp);
  VERIFY(nLong == 5876);
  writeDebugStreamLine("'atoi' testing PASSED");
}


void test_atof()
{
  float  nFloat;
  string sTemp = "5876.3ABC";
  char *pFloatNumber;

  nFloat = atof(sTemp);
  VERIFY(nFloat == 5876.3);

  pFloatNumber = &sTemp;
  nFloat = atof(pFloatNumber);
  VERIFY(nFloat == 5876.3);

  pFloatNumber = "456.73";
  nFloat = atof(pFloatNumber);
  VERIFY(nFloat == 456.73);
  writeDebugStreamLine("'atof' testing PASSED");
}

void test_sscanf()
{
  static string sSource = "23,57,99.3,99.4";
  static const char *pSource2 = "23,57,99.3,99.4";
  static string sFormat = "%d, %d, %f, %f";
  static const char *pFormat = "%d, %d, %f, %f";
  long l1, l2;
  float f1, f2;
  int nNumbParmsScanned;

  nNumbParmsScanned = sscanf("101,102,1.3,1.4", "%d, %d, %f, %f", &l1, &l2, &f1, &f2);
  VERIFY((nNumbParmsScanned == 4) && (l1 == 101) && (l2 == 102) && (f1 == 1.3) && (f2 == 1.4));

  nNumbParmsScanned = sscanf("201,202,2.5,2.6", "%d, %d, %f, %f", &l1, &l2, &f1, &f2);
  VERIFY((nNumbParmsScanned == 4) && (l1 == 201) && (l2 == 202) && (f1 == 2.5) && (f2 == 2.6));

  nNumbParmsScanned = sscanf("301,302.2,3.7,3.8", "%d, %d, %f, %f", &l1, &l2, &f1, &f2);
  VERIFY((nNumbParmsScanned == 2) && (l1 == 301)  && (l2 == 302));

  nNumbParmsScanned = sscanf("401.1,402.2,4.9,4.1", "%d, %d, %f, %f", &l1, &l2, &f1, &f2);
  VERIFY((nNumbParmsScanned == 1) && (l1 == 401));

  nNumbParmsScanned = sscanf(sSource, sFormat, &l1, &l2, &f1, &f2);
  VERIFY((nNumbParmsScanned == 4) && (l1 == 23) && (l2 == 57) && (f1 == 99.3) && (f2 == 99.4));

  nNumbParmsScanned = sscanf(pSource2, pFormat, &l1, &l2, &f1, &f2);
  VERIFY((nNumbParmsScanned == 4) && (l1 == 23) && (l2 == 57) && (f1 == 99.3) && (f2 == 99.4));

  writeDebugStreamLine("'sscanf' testing PASSED");

  test_atoi();
  test_atof();
}


task main()
{
  clearDebugStream();
	writeDebugStreamLine("Starting test of 'sscanf'....");
  test_sscanf();
  writeDebugStreamLine("....'sscanf' test PASSED");
}
