#pragma debuggerWindows(debugStream)


int strlenViaCallByReference1(const string &sString)					{return strlen(sString);}
int strlenViaCallByValue(const string sString)								{return strlen(sString);}
typedef char * PChars;
//int strlenViaCallByReference2(const pChars &pString)					{return strlen(pString);}
int strlenViaCallByValue2(const char *pChars)									{return strlen(pChars);}


void testStrLength(const string &sStringX, const int nLength)
{
	int nStrLength;

	nStrLength = strlen(sStringX);
	ASSERT(nStrLength == nLength);

	nStrLength = strlenViaCallByReference1(sStringX);
	ASSERT(nStrLength == nLength);

	nStrLength = strlenViaCallByValue(sStringX);
	ASSERT(nStrLength == nLength);

	//nStrLength = strlenViaCallByReference2(sStringX);
	//ASSERT(nStrLength == nLength);

	char *pChars = (char *) &sStringX;
	nStrLength = strlenViaCallByValue2(pChars);
	//nStrLength = strlenViaCallByValue2((char *) &sStringX);
	ASSERT(nStrLength == nLength);
}

string theString = "XYZ";
char *pGlobalChars = "1357902468";


task main()
{
	string localString = "98765";
	char *pLocalChars = "abcdefghij";

	clearDebugStream();
	writeDebugStreamLine("Starting test of 'strlen'....");

	testStrLength(*(string *) pLocalChars, strlen(pLocalChars));

	testStrLength("ABCDE", 5);
	testStrLength("54321", 5);
	testStrLength(theString, strlen(theString));
	testStrLength(localString, strlen(localString));
	string *pString;

	pString = (string *) pGlobalChars;
	testStrLength(*(string *) pGlobalChars, strlen(pGlobalChars));
	testStrLength(*pString, strlen(pGlobalChars));
	writeDebugStreamLine("Testing 'strlen' passed");
}
