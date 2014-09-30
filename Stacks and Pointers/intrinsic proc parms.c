int nDummy;
string scratchString;


int getNumericResponse(const string pBuf)
{
  int pos = 0;
  //StringFromChars(scratchString, pBuf);
  //pos = StringFind(scratchString, "=");
  if (pos != 0)
  {
    //StringDelete(scratchString, 0, pos + 1);
    //strTrim(scratchString);
    return atof(scratchString);
  }
  return -1;
}

task main()
{
  string buff;
  int nResult;

 // nResult = getNumericResponse("546");
 // nResult = getNumericResponse("789xxxx");
  //nResult = getNumericResponse("   123   ");
  nResult = getNumericResponse(buff);
}
