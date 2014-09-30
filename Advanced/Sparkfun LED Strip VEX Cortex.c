#pragma config(Sensor, dgtl1,  SCLK,           sensorDigitalOut)
#pragma config(Sensor, dgtl2,  MOSI,           sensorDigitalOut)

typedef enum
{
	kRedOnly   = 0x0000007F,			// Bright Red
	kGreenOnly = 0x00007F00,		  // Bright Green
  kBlueOnly  = 0x007F0000,			// Bright Blue
} TRGBColors;

const bool LOW = false;
const bool HIGH = true;

int nShiftOutBitDelay = 10;
int nDelayBetweenCycles = 25;

const int kNumbOfHistoryCycles = 16;
int nCycleIndex = 0;
long nCylcleTimes[kNumbOfHistoryCycles];

#define kNumbOfLEDs 32							  // 32 LEDs on this strip
long stripColors[kNumbOfLEDs];			// Color is lower 24 bits of 'long' variable


////////////////////////////////////////////////////////////
//
//			Transmit a single byte via SPI Protocol
//
////////////////////////////////////////////////////////////


void writeSPIbyte(unsigned char nByteToSend)
{
  // Max clock transmission rate is 2 MHz for these devices.

  shiftOut(MOSI, SCLK, false, nByteToSend, nShiftOutBitDelay);
  return;

	/*
  int nBitPosition;

	//SCLK is low on entry

	for (nBitPosition = 0; nBitPosition < 8; ++nBitPosition)
  {
    if ((nByteToSend & 0x80) != 0)							// Isolate most significant bit
      SensorValue[MOSI] = HIGH;
    else
      SensorValue[MOSI] = LOW;
    alive();
    alive();
    alive();
    alive();
    alive();
    alive();
    alive();
    alive();
    alive();
    alive();
    alive();
    alive();
    SensorValue[SCLK] = HIGH;// Signal for data value to be latched
    alive();
    alive();
    alive();
    alive();
    alive();
    alive();
    alive();
    alive();
    alive();
    alive();
    SensorValue[SCLK] = LOW;
    alive();
    alive();
    alive();
    alive();
    alive();
    alive();
    alive();
    alive();
    alive();
    nByteToSend <<= 1;
  }
  */
}


////////////////////////////////////////////////////////////
//
//		Setup the I/O Pins for Data and Clock
//
////////////////////////////////////////////////////////////

void setupLEDStrip()
{
  SensorValue[SCLK] = HIGH;
  wait1Msec(5); // delayMicroseconds(500); //Wait for 500us to go into reset
  SensorValue[SCLK] = LOW;
  wait1Msec(5); // delayMicroseconds(500); //Wait for 500us to go into reset
	memset(&stripColors[0], 0, sizeof(stripColors));	//Clear out the array
}

////////////////////////////////////////////////////////////
//
//		Transmit Color Data for 32 LEDs and Activate
//
////////////////////////////////////////////////////////////

void updateSingleLED(long nColorValue)
{
  // Each LED requires 24 bits of data
  // MSB: R7, R6, R5..., G7, G6..., B7, B6... B0
  // Once the 24 bits have been delivered, the IC immediately relays these bits to its neighbor
  // Pulling the clock low for 500us or more causes the IC to post the data.

	writeSPIbyte((unsigned char) (nColorValue & 0xFF));			nColorValue >>= 8;
	writeSPIbyte((unsigned char) (nColorValue & 0xFF));			nColorValue >>= 8;
	writeSPIbyte((unsigned char) (nColorValue & 0xFF));
}

void updateLEDs(void)
{
  int nLEDindex;

	for (nLEDindex = 0; nLEDindex < kNumbOfLEDs; nLEDindex += 1)
	{
		updateSingleLED(stripColors[nLEDindex]);
  }
  //SCLK low for at least 500 microseconds to activate data and clear pass through latches

  SensorValue[SCLK] = LOW;
  wait1Msec(2); // delayMicroseconds(500); //Wait for at least 500us.

  //SensorValue[SCLK] = HIGH;


  static long nLastCylcleTime = 0;
  long nTemp = nSysTime;
  nCylcleTimes[nCycleIndex % kNumbOfHistoryCycles] = nTemp - nLastCylcleTime;
  ++nCycleIndex;
  nLastCylcleTime = nTemp;
}

bool shiftColors(int nCycleIndex, bool bClockwise)
{
  int index;
	long nTemp;

	if (nCycleIndex == 0)
	{
	  stripColors[ 0] = kRedOnly;
	  stripColors[10] = kBlueOnly;
	  stripColors[20] = kGreenOnly;
	}

	if (bClockwise)
	{
		nTemp = stripColors[kNumbOfLEDs - 1];
		for (index = (kNumbOfLEDs - 1); index > 0; --index)
			stripColors[index] = stripColors[index - 1];
		stripColors[0] = nTemp;
	}
	else
	{
		nTemp = stripColors[0];
		for (index = 0; index < (kNumbOfLEDs - 1); ++index)
			stripColors[index] = stripColors[index + 1];
		stripColors[kNumbOfLEDs - 1] = nTemp;
	}
	return (nCycleIndex >= (3 * kNumbOfLEDs));
}


bool shiftRandomColors(int nCycleIndex)
{
  int index;

	for (index = (kNumbOfLEDs - 1); index > 0; --index)
		stripColors[index] = stripColors[index - 1];
	stripColors[0] = rand() & 0x00FFFFFF;
	return (nCycleIndex >= (3 * kNumbOfLEDs));
}


bool xylonScanner(int nCycleIndex)
{
  int index;
	static int nXylonCycleCount = 0;
	int nXylonBeamPosition = 0;
	const int kBeamWidth = 4;
	const int kNumbOfUpdatesPerScanDirection = (kNumbOfLEDs - kBeamWidth);

	memset(&stripColors[0], 0, sizeof(stripColors));
	nXylonCycleCount = nCycleIndex;
	nXylonCycleCount %= (2 * kNumbOfUpdatesPerScanDirection);
	if (nXylonCycleCount < kNumbOfUpdatesPerScanDirection)
	  nXylonBeamPosition = nXylonCycleCount;
	else
	  nXylonBeamPosition = 2 * kNumbOfUpdatesPerScanDirection - nXylonCycleCount;
	for (index = 0; index < kBeamWidth; ++index)
		stripColors[nXylonBeamPosition + index] = kRedOnly;

	return (nCycleIndex >= (6 * kNumbOfUpdatesPerScanDirection));
}

bool pulseColors(int nCycleIndex)
{
  int index;
  long nColor;
	int nColorIndex;
	const int kNumbOfColors = 7;
	const int kNumbOfDisplayStates = 3;

	switch (nCycleIndex / kNumbOfDisplayStates)
  {
  default:
  case 0:       nColor = 0x3F3F3F;      break;
  case 1:       nColor = 0x00007F;      break;
  case 2:       nColor = 0x007F00;      break;
  case 3:       nColor = 0x7F0000;      break;
  case 4:       nColor = 0x003F3F;      break;
  case 5:       nColor = 0x3F3F00;      break;
  case 6:       nColor = 0x3F003F;      break;
  }

	switch (nColorIndex % kNumbOfDisplayStates)
  {
  case 0:		// Solid
	  for (index = 0; index < kNumbOfLEDs; ++index)
			stripColors[index] = nColor;
	  break;

  case 1:		// Atlernating:  OFF, Color, OFF, Color, OFF, Color, ...
	  for (index = 0; index < kNumbOfLEDs; ++index)
			stripColors[index] = (index & 0x01) ? nColor : 0;
	  break;

  case 2:		// Atlernating:  Color, OFF, Color, OFF, Color, OFF, ...
	  for (index = 0; index < kNumbOfLEDs; ++index)
			stripColors[index] = (index & 0x01) ? 0 : nColor;
	  break;
	}
	wait1Msec(200);
	return (nCycleIndex >= (kNumbOfColors * kNumbOfDisplayStates));
}

bool barGraph(int nCycleIndex)
{
  int index;
	int nBarGraphCycleCount;
	int nBaGraphPosition;

	nBarGraphCycleCount = nCycleIndex;
	nBarGraphCycleCount %= (2 * kNumbOfLEDs);
	if (nBarGraphCycleCount < kNumbOfLEDs)
	  nBaGraphPosition = nBarGraphCycleCount;
	else
	  nBaGraphPosition = 2 * kNumbOfLEDs - nBarGraphCycleCount;

	memset(&stripColors[0], 0, sizeof(stripColors));

	// Vary color intensity based on position

	long nBlueColor  = ((long) ((255 * nBaGraphPosition) / kNumbOfLEDs))                 << 16;
	long nGreenColor = ((long) ((255 * (kNumbOfLEDs - nBaGraphPosition)) / kNumbOfLEDs)) <<  8;

	for (index = 0; index < nBaGraphPosition; ++index)
		stripColors[index] = nBlueColor;
	for (index = nBaGraphPosition; index < kNumbOfLEDs; ++index)
		stripColors[index] = nGreenColor;

	return (nCycleIndex >= (4 * kNumbOfLEDs));
}

bool varyIntensity(int nCycleIndex)
{
  int index;
	static int nIntensityCycleCount = 0;
	int nIntensityIndex = 0;
	int nIntensityValue = 0;
	long nColor;
	int nBitShiftColor;

	static const ubyte nIntensityLevels[] =
	{
	  0,
	  0,
	  1,
	  1,
	  2,

	  2,
	  4,
	  6,
	  7,
	  10,

	  20,
	  32,
	  40,
	  50,
	  60,

	  70,
	};
	const int kNumbOfIntensityLevels = sizeof(nIntensityLevels);


	++nIntensityCycleCount;
	nIntensityIndex = (nIntensityCycleCount % (2 * kNumbOfIntensityLevels));
	if (nIntensityIndex < kNumbOfIntensityLevels)
	  nIntensityValue = nIntensityIndex;
	else
	  nIntensityValue = 2 * kNumbOfIntensityLevels - 1- nIntensityIndex;

	memset(&stripColors[0], 0, sizeof(stripColors));
	nColor = nIntensityLevels[nIntensityValue];
  nBitShiftColor = 8 * ((nIntensityCycleCount / (8 * kNumbOfIntensityLevels)) % 3);
  for (index = 0; index < kNumbOfLEDs; ++index)
	{
	  int nCurrIndex;
	  switch (index % 3)
	  {
	  default:
	  case 0:    nCurrIndex = nIntensityValue + (0 * kNumbOfIntensityLevels) / 3;	  break;
	  //case 1:    nCurrIndex = nIntensityValue + (1 * kNumbOfIntensityLevels) / 3;	  break;
	  //case 2:    nCurrIndex = nIntensityValue + (2 * kNumbOfIntensityLevels) / 3;	  break;
	  }
	  nCurrIndex %= kNumbOfIntensityLevels;
	  nColor = nIntensityLevels[nCurrIndex];
	  stripColors[index] = nColor << nBitShiftColor;
	  if ((index == 10) || (index == 20))
		{
		  nBitShiftColor += 8;
		  nBitShiftColor %= 24;
		}
	}
	return (nCycleIndex >= (6 * kNumbOfIntensityLevels));
}


/*
//Throws random colors down the strip array
void test4(void)
{
  if (redIndex == 0)
  {
    rdirect = 2;
  }
  else if (redIndex == kNumbOfLEDs - 2)
  {
    rdirect = -2;
  }
  stripColors[redIndex + rdirect] = 0xFF0000;
  stripColors[redIndex] = 0;
  redIndex += rdirect;
  if (blueIndex == 1)
  {
    bdirect = 2;
  }
  else if (blueIndex == kNumbOfLEDs - 1)
  {
    bdirect = -2;
  }
  stripColors[blueIndex + bdirect] = 0x0000FF;
  stripColors[blueIndex] = 0;
  blueIndex += bdirect;
  if (greenIndex == 0)
  {
    gdirect = 1;
  }
  else if (greenIndex == kNumbOfLEDs - 1)
  {
    gdirect = -1;
  }
  stripColors[greenIndex + gdirect] = 0x00FF00;
  stripColors[greenIndex] = 0;
  greenIndex += gdirect;
}

*/


task main()
{
  //Pre-fill the color array with known values

	setupLEDStrip();
  updateLEDs(); //Push the current color frame to the strip

  wait1Msec(2); //delay(200);

  while (true)
	{
    int nDisplayPattern;

    for (nDisplayPattern = 0; nDisplayPattern <= 7; ++nDisplayPattern)
    {
			int nCylcleCount;
			bool bDisplayFinished = false;
		  memset(&stripColors[0], 0, sizeof(stripColors));	//Clear out the array

      for (nCylcleCount = 0; !bDisplayFinished; ++nCylcleCount)
      {
        switch (nDisplayPattern)
				{
				default:
				case 0:   bDisplayFinished = xylonScanner(nCylcleCount);						break;
				case 1:   bDisplayFinished = pulseColors(nCylcleCount);							break;
				case 2:   bDisplayFinished = pulseColors(nCylcleCount);							break;
				case 3:   bDisplayFinished = shiftColors(nCylcleCount, true);				break;
				case 4:   bDisplayFinished = shiftColors(nCylcleCount, false);			break;
				case 5:   bDisplayFinished = shiftRandomColors(nCylcleCount);				break;
				case 6:   bDisplayFinished = barGraph(nCylcleCount);								break;
				case 7:   bDisplayFinished = varyIntensity(nCylcleCount);						break;
        }
        updateLEDs(); //Push the current color frame to the strip
		    wait1Msec(nDelayBetweenCycles);
		  }
	  }
  }
}
