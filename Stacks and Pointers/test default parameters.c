void foo( int a, int b = 10 )
{
	writeDebugStreamLine("%d %d", a, b);
}

short nShort = 10000;
long nLong = 100000;
task main()
{
	// now has compile error.
	foo( 20 );
	// works
	foo( 20, 30 );

	while (true)
	{
		string string1 = "AAA";
		string string2 = "BBB";
		char chars[30] = "0123456789";
		char *pChar = &chars;

		strcat(string1, string2);
		strcat(pChar, string2);

		strcat(string1, "hello");
		strcat(pChar, "hello");

		wait1Msec(100000);
		wait1Msec(nShort);
		wait1Msec(nLong);
	}
}
