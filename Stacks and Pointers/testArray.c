task main()
{
  ubyte chars[10] = {0,   1,  2,  3,  4,  5,  6,  7,  8,  9};
  short words[10] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
  long longs[10]  = {20, 21, 22, 23, 24, 25, 26, 27, 28, 29};

  ubyte *pChars  = &chars;
  char  *pChars2 = &chars;
  short *pWords  = &words;
  long  *pLongs = &longs;

	int ii;
	long ll;
	int jj;// = rand();



	for (ii = 0; ii < 5; ii += 1)
  {
    if ((ii % 2) == 0)
    {
	    // 'short' index variable

      jj = chars[ii];
		  jj = words[ii];
		  jj = longs[ii];
		}
		else
		{
		  // 'short' index variable on pointer variable

		  jj = pChars[ii];
		  jj = pWords[ii];
		  jj = pLongs[ii];
		}
	}


  for (ll = 0; ll < 5; ll += 1)
  {
    if ((ll % 2) == 0)
    {
      // 'long' index variable

		  jj = chars[ll];
		  jj = words[ll];
		  jj = longs[ll];
		}
		else
		{
		  // 'long' index variable on pointer variable

		  jj = pChars[ll];
		  jj = pWords[ll];
		  jj = pLongs[ll];
		}
	}
}
