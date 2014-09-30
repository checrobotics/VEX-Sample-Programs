
task main()
{
	int		i;
	char	*p;
	char	*q;

	const int kArraySizes = 10;
	unsigned char    myarray1[kArraySizes];
	unsigned char    myarray2[kArraySizes];

	for (i = 0; i < kArraySizes; ++i)
	{
		myarray1[i] = i;
		myarray2[i] = 100 + i;
	}
	wait1Msec(1500);

	p = &myarray1[0];
	q = &myarray2[0];

	for(i = 0; i < kArraySizes; i++)
		*p++ = *q++;

	while (true)
	{
		wait1Msec(10);
		wait1Msec(10);
	}
	return;
}
