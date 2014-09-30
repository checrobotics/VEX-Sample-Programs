#define printf writeDebugStream

task main()
{
  char baseData[] = "25 December 2012";

  long day;
  long year;				// Needs to be a 'long' for 'sscanf' usage.
  char monthname[20];

  clearDebugStream();
  writeDebugStreamLine("Starting 'sscanf' test.....");

  sscanf(baseData, "%d %s %d", &day, monthname, &year);
  printf("Day: %d\nMonth: %s\nYear: %d\n", day, monthname, year);
  VERIFY(day == 25);
  VERIFY(year == 2012);
  VERIFY(strcmp(monthname, "December") == 0);


  string testString1 = "Hello";
	string testString2 = "World!";

	strcat(testString1, testString2);
  VERIFY(strcmp(testString1, "HelloWorld!") == 0);

	writeDebugStreamLine("...End 'sscanf' test.....PASSED");
}
