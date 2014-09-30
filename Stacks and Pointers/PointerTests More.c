
#pragma debuggerwindows(debugStream)

void failCase1()
{
	char myChar = 'D';
	char *pChar = &myChar;
	writeDebugStreamLine("Address: %p", pChar);
}

void failCase2()
{
	int a[10] = {5,10,15,20,25,30,35,40,45,50};
	int *aPointer;
	int aValue, aValue2;

	aPointer = &a[0];
	aValue = *(aPointer+1);
	//aPointer = (aPointer + aPointer);
	//aPointer += aPointer;
	aValue2 = aPointer++;
}

void failCase3()
{
	int testValue = 0;
	int *ptr;
	if(ptr == 0)  //if(ptr == NULL) - Can we tell if a pointer in uninitialized?
	{
		testValue = 1;
	}
	else
	{
		testValue = 2;
	}
}

void failCase4()
{
	static int counter;  //Should this reset to zero between "runs"
	int nonStaticCounter;
	writeDebugStreamLine("S:%d / N:%d", counter, nonStaticCounter);
	counter++;
	nonStaticCounter++;

}

task main()
{
	failCase1();
	failCase2();
	failCase3();

  while(true)
	{
		failCase4();
		wait1Msec(50);
	}
}
