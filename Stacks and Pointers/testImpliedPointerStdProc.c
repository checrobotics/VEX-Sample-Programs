struct
{
	char myarray[20];
} testStruct;

void foo( testStruct *p )
{
	writeDebugStreamLine("%s", p->myarray );
}

#define	ARRAYSIZE	32
unsigned char MyArray[ARRAYSIZE];

void Init( unsigned char *data, int len )
{
	unsigned char *p = data;
	int		i;

	// This seems to cause major crash on compile
	for(i = 0; i < len; i++)
	{
		*p++ = i;
	}
}
typedef struct {
	int	a;
	int	b;
} testStruct2;

testStruct	s;

testStruct2 *foo2()
{
	testStruct2	*f = &s;
	return (f);
}

task main()
{
	Init(&MyArray, ARRAYSIZE );

	testStruct2	*f;

	// did not compile
	f = foo2();

	// works
	f = (testStruct2 *)foo2();

	testStruct MyStruct;

	sprintf(MyStruct.myarray, "Hello");

	foo( MyStruct );   // does not send address of MyStruct
	foo( &MyStruct ); // works

	while(1)
	{
		wait1Msec(10);
	}
}
