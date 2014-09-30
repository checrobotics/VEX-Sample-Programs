#pragma noprolog
#pragma debuggerWindows(debugStream)

typedef struct
{
  int aa;
  char * pp;
  string ss;
  int bb;
} TStruct;

void testCharPointerInialization1(string &sStringVar)
{
  writeDebugStreamLine(sStringVar);
}

void testCharPointerInialization2(const string &sStringVar)
{
  writeDebugStreamLine(sStringVar);
}

void testCharPointerInialization3(TStruct &nStruct, const string &sValue, int nStrLength)
{
  nStruct.pp = sValue;
  nStruct.ss = nStruct.pp;
  nStruct.aa = strlen(nStruct.pp);
  ASSERT(nStruct.aa == nStrLength);
  writeDebugStreamLine("&Struct element access: '%d' chars are '%s'", strlen(nStruct.pp), nStruct.pp);
}

TStruct xx;

void testCharPointerInialization()
{
  static const char *pChars1 = "ABCDEFGHIJ";
  static const char *pChars2 = "BCDEFGHIJ";
  static char *pChars3 = "CDEFGHIJ";
  static const char *pChars4 = "DEFGHIJ";
  string sTemp = pChars3;
  string sTemp2;

  pChars1 = "ABCDEFGHIJ";
  sTemp = pChars1;
  pChars1 = sTemp;
  ASSERT(sTemp == "ABCDEFGHIJ");
  sTemp2 = pChars2;
  ASSERT(sTemp2 == "BCDEFGHIJ");
  ASSERT(pChars1[0] == 'A');
  ASSERT(pChars1[1] == 'B');
  ASSERT(pChars1[2] == 'C');
  ASSERT(pChars1[3] == 'D');
  ASSERT(pChars1[4] == 'E');
  ASSERT(pChars1[5] == 'F');
  ASSERT(pChars1[6] == 'G');
  clearDebugStream();
  writeDebugStreamLine(pChars1);
  writeDebugStreamLine(sTemp);
  testCharPointerInialization1(sTemp);
  testCharPointerInialization2("WXYZ");
  writeDebugStreamLine("%%s formating: '%s'", pChars1);
  writeDebugStreamLine("%%s formating: '%s'", "ABC");
  writeDebugStreamLine("%%s formating: '%s'", pChars2);
  writeDebugStreamLine("%%s formating: '%s'", sTemp);
  {
    xx.pp = "9876543210";
    xx.pp = sTemp;
    testCharPointerInialization3(xx, "aAbBcCdDeE", strlen("aAbBcCdDeE"));
	  xx.aa = 59;
	  xx.ss = xx.pp;
	  xx.aa = strlen(pChars1);
	  ASSERT(xx.aa == 10);
	  xx.aa = strlen(sTemp);
	  ASSERT(xx.aa == 10);

	  sTemp = "Empty";
	  xx.pp = "999999";
	  sTemp = xx.pp;
	  xx.aa = strlen(xx.pp);
	  ASSERT(xx.aa == 6);
	  xx.bb = strlen(xx.ss);
	  ASSERT(xx.aa == 6);
    writeDebugStreamLine("Struct element access: '%d' chars are '%s'", strlen(xx.pp), xx.pp);
	}
  return;
}

static char *pDummy1 = "ZYWVUT";
static string sDummy2 = pDummy1;

void testStringInialization()
{
  static string str1 = "ABCDEabcde";
  static char *pChars = "ABCDEFG123456789";
  char *pChars2 = "ABCDEFGHIJ";
  static char cChars2[] = "0123456789";
  char cChars[] = "0123456789";

  //VERIFY(cChars[0] == '0');
  //VERIFY(cChars[1] == '1');
  //VERIFY(cChars[2] == '2');
  //VERIFY(cChars[3] == '3');
  //VERIFY(cChars[4] == '4');
  //VERIFY(cChars[5] == '5');
  //VERIFY(cChars[6] == '6');

  VERIFY(pChars[0] == 'A');
  VERIFY(pChars[1] == 'B');
  VERIFY(pChars[2] == 'C');
  VERIFY(pChars[3] == 'D');
  VERIFY(pChars[4] == 'E');
  VERIFY(pChars[5] == 'F');
  VERIFY(pChars[6] == 'G');

  VERIFY(str1 == "ABCDEabcde");

  writeDebugStreamLine("'string initialization' testing passed");
  return;
}

task main()
{
	clearDebugStream();
	writeDebugStreamLine("Starting test 'char *' initialization ...");

	testCharPointerInialization();
	testCharPointerInialization();
	testStringInialization();

	writeDebugStreamLine("...Testing 'char *' initialization PASSED");
}
