struct
{
	char    myarray[20];
} testStruct;

testStruct MyStruct;

int *foo()
{
	testStruct  *p = &MyStruct;
	return( (int *)&MyStruct );
}

testStruct *bar()
{
	testStruct  *p = &MyStruct;
	return( p );
}

task main()
{
	testStruct  *p;
	p = (testStruct *)foo();
}
