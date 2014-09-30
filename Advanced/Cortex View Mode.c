//Global Variable Declarations
const short leftButton = 1;
const short centerButton = 2;
const short rightButton = 4;
short sensorChoice;
short portChoice;
short count;

//Task and Function Prototypes
void waitForPress();
void waitForRelease();
void clearPorts();

task sensorChooser();
task digitalPortChooser();
task analogPortChooser();
void menuTracker();

task display();
void analogSensorSetup(tSensors sensorPort);
void digitalSensorSetup(tSensors sensorPort);

//Main------------------------------------------------------------
task main()
{
  startTask(sensorChooser);
  while(true)
  {
    wait1Msec(50);
  }
}
//----------------------------------------------------------------

//sensorChooser - allows you to choose which sensor you'd like to pick
task sensorChooser()
{
  //Junk Cleanup from previous runs
  clearLCDLine(0);
  clearLCDLine(1);
  clearPorts();
  waitForRelease();
  stopTask(display);
  stopTask(digitalPortChooser);
  stopTask(analogPortChooser);

  hogCPU();

  count = 0;
  while(true)
  {
    switch(count){
    case 0:
      //Touch
      displayLCDCenteredString(0, "Touch Sensor");
      displayLCDCenteredString(1, "<     Enter    >");
      waitForPress();

      if(nLCDButtons == centerButton)
      {
        waitForRelease();
        sensorChoice = 0;
        releaseCPU();
        startTask(digitalPortChooser);
      }
      else if(nLCDButtons == leftButton)
      {
        waitForRelease();
        count = 6;
      }
      else if(nLCDButtons == rightButton)
      {
        waitForRelease();
        count++;
      }

      break;
    case 1:
      //Quadrature Encoder
      displayLCDCenteredString(0, "Quad Encoder");
      displayLCDCenteredString(1, "<     Enter    >");
      waitForPress();

      if(nLCDButtons == centerButton)
      {
        waitForRelease();
        sensorChoice = 1;
        releaseCPU();
        startTask(digitalPortChooser);
      }
      else
        menuTracker();
      break;
    case 2:
      //Ultrasonic
      displayLCDCenteredString(0, "Ultrasonic");
      displayLCDCenteredString(1, "<     Enter    >");
      waitForPress();

      if(nLCDButtons == centerButton)
      {
        waitForRelease();
        sensorChoice = 2;
        releaseCPU();
        startTask(digitalPortChooser);
      }
      else
        menuTracker();
      break;
    case 3:
      //Light
      displayLCDCenteredString(0, "Light Sensor");
      displayLCDCenteredString(1, "<     Enter    >");
      waitForPress();

     if(nLCDButtons == centerButton)
      {
        waitForRelease();
        sensorChoice = 3;
        releaseCPU();
        startTask(analogPortChooser);
      }
      else
        menuTracker();
      break;
    case 4:
      //Line Tracker
      displayLCDCenteredString(0, "Line Tracker");
      displayLCDCenteredString(1, "<     Enter    >");
      waitForPress();

      if(nLCDButtons == centerButton)
      {
        waitForRelease();
        sensorChoice = 4;
        releaseCPU();
        startTask(analogPortChooser);
      }
      else
        menuTracker();
      break;
    case 5:
      //Potentiometer
      displayLCDCenteredString(0, "Potentiometer");
      displayLCDCenteredString(1, "<     Enter    >");
      waitForPress();

      if(nLCDButtons == centerButton)
      {
        waitForRelease();
        sensorChoice = 5;
        releaseCPU();
        startTask(analogPortChooser);
      }
      else
        menuTracker();
      break;
    case 6:
      //Accelerometer
      displayLCDCenteredString(0, "Accelerometer");
      displayLCDCenteredString(1, "<     Enter    >");
      waitForPress();

      if(nLCDButtons == centerButton)
      {
        waitForRelease();
        sensorChoice = 6;
        releaseCPU();
        startTask(analogPortChooser);
      }
      else if(nLCDButtons == leftButton)
      {
        waitForRelease();
        count--;
      }
      else if(nLCDButtons == rightButton)
      {
        waitForRelease();
        count = 0;
      }
      break;
    }
  }
}
//----------------------------------------------------------------

//digitalPortChooser - allows you to choose which port you'd like to pick
task digitalPortChooser()
{
  stopTask(sensorChooser);
  hogCPU();

  count = 1;  //Chooses the starting point

  while(true)
  {
    switch(count){
    case 0:
      //Back Option
      displayLCDCenteredString(0, "Back to Sensors");
      displayLCDCenteredString(1, "<     Enter    >");
      waitForPress();

      if(nLCDButtons == centerButton)
      {
        waitForRelease();
        releaseCPU();
        startTask(sensorChooser);
      }
      else if(nLCDButtons == leftButton)
      {
        waitForRelease();
        count = 12;
      }
      else if(nLCDButtons == rightButton)
      {
        waitForRelease();
        count++;
      }
      break;
    case 1:
      //Digital 1
      displayLCDCenteredString(0, "DIGITAL 1");
      displayLCDCenteredString(1, "<     Enter    >");
      waitForPress();

      if(nLCDButtons == centerButton)
      {
        waitForRelease();
        portChoice = 1;
        releaseCPU();
        startTask(display);
      }
      else
        menuTracker();
      break;
    case 2:
      //Digital 2
      displayLCDCenteredString(0, "DIGITAL 2");
      displayLCDCenteredString(1, "<     Enter    >");
      waitForPress();

      if(nLCDButtons == centerButton)
      {
        waitForRelease();
        portChoice = 2;
        releaseCPU();
        startTask(display);
      }
      else
        menuTracker();
      break;
    case 3:
      //Digital 3
      displayLCDCenteredString(0, "DIGITAL 3");
      displayLCDCenteredString(1, "<     Enter    >");
      waitForPress();

      if(nLCDButtons == centerButton)
      {
        waitForRelease();
        portChoice = 3;
        releaseCPU();
        startTask(display);
      }
      else
        menuTracker();
      break;
    case 4:
      //Digital 4
      displayLCDCenteredString(0, "DIGITAL 4");
      displayLCDCenteredString(1, "<     Enter    >");
      waitForPress();

      if(nLCDButtons == centerButton)
      {
        waitForRelease();
        portChoice = 4;
        releaseCPU();
        startTask(display);
      }
      else
        menuTracker();
      break;
    case 5:
      //Digital 5
      displayLCDCenteredString(0, "DIGITAL 5");
      displayLCDCenteredString(1, "<     Enter    >");
      waitForPress();

      if(nLCDButtons == centerButton)
      {
        waitForRelease();
        portChoice = 5;
        releaseCPU();
        startTask(display);
      }
      else
        menuTracker();
      break;
    case 6:
      //Digital 6
      displayLCDCenteredString(0, "DIGITAL 6");
      displayLCDCenteredString(1, "<     Enter    >");
      waitForPress();

      if(nLCDButtons == centerButton)
      {
        waitForRelease();
        portChoice = 6;
        releaseCPU();
        startTask(display);
      }
      else
        menuTracker();
      break;
    case 7:
      //Digital 7
      displayLCDCenteredString(0, "DIGITAL 7");
      displayLCDCenteredString(1, "<     Enter    >");
      waitForPress();

      if(nLCDButtons == centerButton)
      {
        waitForRelease();
        portChoice = 7;
        releaseCPU();
        startTask(display);
      }
      else
        menuTracker();
      break;
    case 8:
      //Digital 8
      displayLCDCenteredString(0, "DIGITAL 8");
      displayLCDCenteredString(1, "<     Enter    >");
      waitForPress();

      if(nLCDButtons == centerButton)
      {
        waitForRelease();
        portChoice = 8;
        releaseCPU();
        startTask(display);
      }
      else
        menuTracker();
      break;
    case 9:
      //Digital 9
      displayLCDCenteredString(0, "DIGITAL 9");
      displayLCDCenteredString(1, "<     Enter    >");
      waitForPress();

      if(nLCDButtons == centerButton)
      {
        waitForRelease();
        portChoice = 9;
        releaseCPU();
        startTask(display);
      }
      else
        menuTracker();
      break;
    case 10:
      //Digital 10
      displayLCDCenteredString(0, "DIGITAL 10");
      displayLCDCenteredString(1, "<     Enter    >");
      waitForPress();

      if(nLCDButtons == centerButton)
      {
        waitForRelease();
        portChoice = 10;
        releaseCPU();
        startTask(display);
      }
      else
        menuTracker();
      break;
    case 11:
      //Digital 2
      displayLCDCenteredString(0, "DIGITAL 11");
      displayLCDCenteredString(1, "<     Enter    >");
      waitForPress();

      if(nLCDButtons == centerButton)
      {
        waitForRelease();
        portChoice = 11;
        releaseCPU();
        startTask(display);
      }
      else
        menuTracker();
      break;
    case 12:
      //Digital 12
      displayLCDCenteredString(0, "DIGITAL 12");
      displayLCDCenteredString(1, "<     Enter    >");
      waitForPress();

      if(nLCDButtons == centerButton)
      {
        waitForRelease();
        portChoice = 12;
        releaseCPU();
        startTask(display);
      }
      else if(nLCDButtons == leftButton)
      {
        waitForRelease();
        count--;
      }
      else if(nLCDButtons == rightButton)
      {
        waitForRelease();
        count = 0;
      }
      break;
    }
  }
}
//----------------------------------------------------------------

//analogPortChooser - allows you to choose which port you'd like to pick
task analogPortChooser()
{
  stopTask(sensorChooser);
  hogCPU();

  count = 1;//Chooses the starting point

  while(true)
  {
    switch(count){
    case 0:
      //Back Option
      displayLCDCenteredString(0, "Back to Sensors");
      displayLCDCenteredString(1, "<     Enter    >");
      waitForPress();

      if(nLCDButtons == centerButton)
      {
        waitForRelease();
        releaseCPU();
        startTask(sensorChooser);
      }
      else if(nLCDButtons == leftButton)
      {
        waitForRelease();
        count = 8;
      }
      else if(nLCDButtons == rightButton)
      {
        waitForRelease();
        count++;
      }
      break;
    case 1:
      //Analog 1
      displayLCDCenteredString(0, "ANALOG 1");
      displayLCDCenteredString(1, "<     Enter    >");
      waitForPress();

      if(nLCDButtons == centerButton)
      {
        waitForRelease();
        portChoice = 13;
        releaseCPU();
        startTask(display);
      }
      else
        menuTracker();
      break;
    case 2:
      //Analog 2
      displayLCDCenteredString(0, "ANALOG 2");
      displayLCDCenteredString(1, "<     Enter    >");
      waitForPress();

      if(nLCDButtons == centerButton)
      {
        waitForRelease();
        portChoice = 14;
        releaseCPU();
        startTask(display);
      }
      else
        menuTracker();
      break;
    case 3:
      //Analog 3
      displayLCDCenteredString(0, "ANALOG 3");
      displayLCDCenteredString(1, "<     Enter    >");
      waitForPress();

      if(nLCDButtons == centerButton)
      {
        waitForRelease();
        portChoice = 15;
        releaseCPU();
        startTask(display);
      }
      else
        menuTracker();
      break;
    case 4:
      //Analog 4
      displayLCDCenteredString(0, "ANALOG 4");
      displayLCDCenteredString(1, "<     Enter    >");
      waitForPress();

      if(nLCDButtons == centerButton)
      {
        waitForRelease();
        portChoice = 16;
        releaseCPU();
        startTask(display);
      }
      else
        menuTracker();
      break;
    case 5:
      //Analog 5
      displayLCDCenteredString(0, "ANALOG 5");
      displayLCDCenteredString(1, "<     Enter    >");
      waitForPress();

      if(nLCDButtons == centerButton)
      {
        waitForRelease();
        portChoice = 17;
        releaseCPU();
        startTask(display);
      }
      else
        menuTracker();
      break;
    case 6:
      //Analog 6
      displayLCDCenteredString(0, "ANALOG 6");
      displayLCDCenteredString(1, "<     Enter    >");
      waitForPress();

      if(nLCDButtons == centerButton)
      {
        waitForRelease();
        portChoice = 18;
        releaseCPU();
        startTask(display);
      }
      else
        menuTracker();
      break;
    case 7:
      //Analog 7
      displayLCDCenteredString(0, "ANALOG 7");
      displayLCDCenteredString(1, "<     Enter    >");
      waitForPress();

      if(nLCDButtons == centerButton)
      {
        waitForRelease();
        portChoice = 19;
        releaseCPU();
        startTask(display);
      }
      else
        menuTracker();
      break;
    case 8:
      //Analog 8
      displayLCDCenteredString(0, "ANALOG 8");
      displayLCDCenteredString(1, "<     Enter    >");
      waitForPress();

      if(nLCDButtons == centerButton)
      {
        waitForRelease();
        portChoice = 20;
        releaseCPU();
        startTask(display);
      }
      if(nLCDButtons == leftButton)
      {
        waitForRelease();
        count--;
      }
      else if(nLCDButtons == rightButton)
      {
        waitForRelease();
        count = 0;
      }
      break;
    }
  }
}
//----------------------------------------------------------------

//Clear Ports-----------------------------------------------------
void clearPorts()
{
  hogCPU();
  SensorType[in1] = sensorNone;
  SensorType[in2] = sensorNone;
  SensorType[in3] = sensorNone;
  SensorType[in4] = sensorNone;
  SensorType[in5] = sensorNone;
  SensorType[in6] = sensorNone;
  SensorType[in7] = sensorNone;
  SensorType[in8] = sensorNone;

  SensorType[dgtl1] = sensorNone;
  SensorType[dgtl2] = sensorNone;
  SensorType[dgtl3] = sensorNone;
  SensorType[dgtl4] = sensorNone;
  SensorType[dgtl5] = sensorNone;
  SensorType[dgtl6] = sensorNone;
  SensorType[dgtl7] = sensorNone;
  SensorType[dgtl8] = sensorNone;
  SensorType[dgtl9] = sensorNone;
  SensorType[dgtl10] = sensorNone;
  SensorType[dgtl11] = sensorNone;
  SensorType[dgtl12] = sensorNone;
  releaseCPU();
}
//----------------------------------------------------------------

//Wait for Press--------------------------------------------------
void waitForPress()
{
  while(nLCDButtons == 0)
  {
    wait1Msec(5);
  }
}
//----------------------------------------------------------------

//Wait for Release------------------------------------------------
void waitForRelease()
{
  while(nLCDButtons != 0)
  {
    wait1Msec(5);
  }
}
//----------------------------------------------------------------

//Function to increment and decriment count - small savings on space
void menuTracker()
{
  if(nLCDButtons == leftButton)
  {
    waitForRelease();
    count--;
  }
  else if(nLCDButtons == rightButton)
  {
    waitForRelease();
    count++;
  }
}
//----------------------------------------------------------------

//Display---------------------------------------------------------
task display()
{
  stopTask(analogPortChooser);
  stopTask(digitalPortChooser);
  hogCPU();

  switch(portChoice){
  case 1:
    //Digital Port 1
    digitalSensorSetup(dgtl1);
    break;
  case 2:
    //Digital Port 2
    digitalSensorSetup(dgtl2);
    break;
  case 3:
    //Digital Port 3
    digitalSensorSetup(dgtl3);
    break;
  case 4:
    //Digital Port 4
    digitalSensorSetup(dgtl4);
    break;
  case 5:
    //Digital Port 5
    digitalSensorSetup(dgtl5);
    break;
  case 6:
    //Digital Port 6
    digitalSensorSetup(dgtl6);
    break;
  case 7:
    //Digital Port 7
    digitalSensorSetup(dgtl7);
    break;
  case 8:
    //Digital Port 8
    digitalSensorSetup(dgtl8);
    break;
  case 9:
    //Digital Port 9
    digitalSensorSetup(dgtl9);
    break;
  case 10:
    //Digital Port 10
    digitalSensorSetup(dgtl10);
    break;
  case 11:
    //Digital Port 11
    digitalSensorSetup(dgtl11);
    break;
  case 12:
    //Digital Port 12
    digitalSensorSetup(dgtl12);
    break;
  case 13:
    //Analog Port 1
    analogSensorSetup(in1);
    break;
  case 14:
    //Analog Port 2
    analogSensorSetup(in2);
    break;
  case 15:
    //Analog Port 3
    analogSensorSetup(in3);
    break;
  case 16:
    //Analog Port 4
    analogSensorSetup(in4);
    break;
  case 17:
    //Analog Port 5
    analogSensorSetup(in5);
    break;
  case 18:
    //Analog Port 6
    analogSensorSetup(in6);
    break;
  case 19:
    //Analog Port 7
    analogSensorSetup(in7);
    break;
  case 20:
    //Analog Port 8
    analogSensorSetup(in8);
    break;
  }
  releaseCPU();
  startTask(sensorChooser);
}
//----------------------------------------------------------------

//Creates the analog sensor to be displayed
void analogSensorSetup(tSensors sensorPort)
{
  switch(sensorChoice){
  case 3:
    SensorType[sensorPort] = sensorLineFollower; //Change to sensorReflection
    clearLCDLine(0);
    displayLCDPos(0,0);
    displayNextLCDString("Light:");
    while(nLCDButtons != 2)
    {
      clearLCDLine(1);
      displayLCDPos(1,0);
      displayNextLCDNumber(SensorValue[sensorPort], 4);
      wait1Msec(100);
    }
    break;
  case 4:
    SensorType[sensorPort] = sensorLineFollower;
    clearLCDLine(0);
    displayLCDPos(0,0);
    displayNextLCDString("Line Tracker:");
    while(nLCDButtons != 2)
    {
      clearLCDLine(1);
      displayLCDPos(1,0);
      displayNextLCDNumber(SensorValue[sensorPort], 4);
      wait1Msec(100);
    }
    break;
  case 5:
    SensorType[sensorPort] = sensorPotentiometer;
    clearLCDLine(0);
    displayLCDPos(0,0);
    displayNextLCDString("Potentiometer:");
    while(nLCDButtons != 2)
    {
      clearLCDLine(1);
      displayLCDPos(1,0);
      displayNextLCDNumber(SensorValue[sensorPort], 4);
      wait1Msec(100);
    }
    break;
  case 6:
    SensorType[sensorPort] = sensorAccelerometer;
    clearLCDLine(0);
    displayLCDPos(0,0);
    displayNextLCDString("Accelerometer:");
    while(nLCDButtons != 2)
    {
      clearLCDLine(1);
      displayLCDPos(1,0);
      displayNextLCDNumber(SensorValue[sensorPort], 4);
      wait1Msec(100);
    }
    break;
  }
}
//----------------------------------------------------------------

//Creates the digital sensor to be displayed----------------------
void digitalSensorSetup(tSensors sensorPort)
{
  switch(sensorChoice){
  case 0:
    SensorType[sensorPort] = sensorTouch;
    clearLCDLine(0);
    displayLCDPos(0,0);
    displayNextLCDString("Touch:");
    while(nLCDButtons != 2)
    {
      clearLCDLine(1);
      displayLCDPos(1,0);
      displayNextLCDNumber(SensorValue[sensorPort], 1);
      wait1Msec(100);
    }
    break;
  case 1:
    SensorType[sensorPort] = sensorQuadEncoder;
    clearLCDLine(0);
    displayLCDPos(0,0);
    displayNextLCDString("Quad Encoder:");
    while(nLCDButtons != 2)
    {
      clearLCDLine(1);
      displayLCDPos(1,0);
      displayNextLCDNumber(SensorValue[sensorPort], 6);
      wait1Msec(100);
    }
    break;
  case 2:
    SensorType[sensorPort] = sensorSONAR_TwoPins_cm;
    clearLCDLine(0);
    displayLCDPos(0,0);
    displayNextLCDString("Ultrasonic (cm):");
    while(nLCDButtons != 2)
    {
      clearLCDLine(1);
      displayLCDPos(1,0);
      displayNextLCDNumber(SensorValue[sensorPort], 4);
      wait1Msec(100);
    }
    break;
  }
}
//----------------------------------------------------------------
