//------------------------------------------
typedef long  uint32_t;
typedef unsigned short uint16_t;

typedef struct
{
	uint32_t ACR;
	uint32_t KEYR;
	uint32_t OPTKEYR;
	uint32_t SR;
	uint32_t CR;
	uint32_t AR;
	uint32_t RESERVED;
	uint32_t OBR;
	uint32_t WRPR;
} FLASH_TypeDef;

// constants
#define CONSTANT    ((uint32_t)0x45670123)

// clobal struct for demo
FLASH_TypeDef       testf;

// test function

void TestFunction(void)
{
	FLASH_TypeDef   *f = &testf;
	long  *p;
	long   c1 = CONSTANT;


	// This does not work
	f->KEYR = CONSTANT;
	writeDebugStreamLine("KEYR is %08X", f->KEYR );

	// This works
	f->KEYR = c1;
	writeDebugStreamLine("KEYR is %08X", f->KEYR );
	c1 += CONSTANT;

	// As does this
	testf.KEYR = CONSTANT;
	writeDebugStreamLine("KEYR is %08X", f->KEYR );

	// get address of variable
	p = &f->KEYR;

	// this does not work
	*p = CONSTANT;
	writeDebugStreamLine("KEYR is %08X", f->KEYR );

	// this does
	*p = c1;
	writeDebugStreamLine("KEYR is %08X", f->KEYR );
}

task main()
{
	TestFunction();

	while(1);
}
