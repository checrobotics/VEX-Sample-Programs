
int globalScopeInt = 6;
byte globalScopebytes[5] = {7, 8, 9, 10, 11};

void procWithStaticVars(int parm1, int parm2, int parm3)
{
  static int staticInt0 = 55;
  static byte staticByte0 = 1;
  int localxyz = parm2 + parm3;
  long localabc = staticInt0 + 35;

  staticByte0 = localabc;
  parm1 = localxyz + localabc;
  {
    int nestedFirst00[5] = {41, 42, 43, -55, 45};
    int nestedFirst01[5] = {41, 42, 43, -55, 45};
    int nestedFirst03[5] = {41, 42, 43, -55, 45};
    static byte staticByte0 = 1;
    byte nestedFirst1;
    int nestedFirst2;
    byte nestedFirst3;
	  {
	    int x0[5] = {411, 242, 243, -525, 245};
	    static byte xx0 = 1;
	    byte xx1;
		   {
		    long longxyz;
		    static int intABC;
		    static long longABC;
		    int x0[5];
		    static byte xx0 = 1;
		    byte xx1;
		    int xxx2;
		    byte xxxx3;
		  }
		  int xxx2;
	    byte xxxx3;
	  }
	 }
  {
    int nestedSecond[4];
    static byte staticByte0 = 1;
    byte nestedSecond1;
    int nestedSecond2;
    byte nestedSecond3;
  }
  {
    byte nestedThird[3];
     byte nestedThird1;
    int nestedThird2;
    byte nestedThird3;
  }

  wait1Msec(10);
}

long globalLong1[3];

void procWithLocalVars(int parm1, int parm2, int parm3)
{
  byte localByte2 = 3;
  byte localByte3 = 3;
  byte localByte4 = 3;
  int localInt2 = 2;
  byte localByte5 = 3;

  parm1 = parm2 + 3 + parm1 + 55;
  wait1Msec(10);
  {
    int nestedFirst0[5];
    byte nestedFirst1;
    int nestedFirst2;
    byte nestedFirst3;
  }
  {
    int nestedSecond[4];
    byte nestedSecond1;
    int nestedSecond2;
    byte nestedSecond3;
  }
  {
    byte nestedThird[3];
     byte nestedThird1;
    int nestedThird2;
    byte nestedThird3;
  }
}

long globalLong2[3];
long globalLong3[3];


void recursiveProcWithLocalAndStaticVars(int parm1, int parm2, int parm3)
{
  int localInt3;
  static byte staticByte3 = 5;
  byte localByte3;
  static ubyte nRecursionCount = 0;

  if (nRecursionCount >= 20)
    return;

  ++nRecursionCount;
  wait1Msec(1);
  recursiveProcWithLocalAndStaticVars(nRecursionCount + 1, 2, 3);
  --nRecursionCount;
}

long globalLong4[3];
long globalLong5[3];

task main()
{
  int nLocalTask0 = 57;
  int nLocalTask1 = 58;

  recursiveProcWithLocalAndStaticVars(54, nLocalTask0, nLocalTask1);

  for (int nIndex = 0; nLocalTask0 < 100; ++nLocalTask0)
  {
    recursiveProcWithLocalAndStaticVars(nIndex, nLocalTask0, nLocalTask1);
	  procWithStaticVars(nIndex, nLocalTask0, nLocalTask1);
	  procWithLocalVars(nIndex, nLocalTask0, nLocalTask1);
	  wait1Msec(10);
	}
	{
	  int nestedLocalTask2;
	  int nestedLocalTask3;
	  int nestedLocalTask4;
	  int nestedLocalTask5;
	  int nestedLocalTask6;

	  recursiveProcWithLocalAndStaticVars(nestedLocalTask2, nestedLocalTask3, nLocalTask1);
  }
}
