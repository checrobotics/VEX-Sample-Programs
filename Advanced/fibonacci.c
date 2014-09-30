long fib_via_recursion (short n)
{
  if (n <= 2)
    return 1;
  else
    return fib_via_recursion(n-1) + fib_via_recursion(n-2);
}

long fib_via_iteration (short N)
{
  long k1, k2, k3;
  k1 = k2 = k3 = 1;
  for (int j = 3; j <= N; j++)
  {
    k3 = k1 + k2;
    k1 = k2;
    k2 = k3;
  }
  return k3;
}

long nElapsedTime_recursion;
long nElapsedTime_iteration;
long nResult_via_recursion;
long nResult_via_iteration;
long ii;

task main()
{
  clearDebugStream();
  writeDebugStreamLine("  N:     fib(N)   Recursive     Iterative");
  for (long i = 1; i < 1000; ++i)
  {

    nElapsedTime_recursion = nPgmTime;
    nResult_via_recursion = fib_via_recursion(i);
    nElapsedTime_recursion = nPgmTime - nElapsedTime_recursion;

    nElapsedTime_iteration = nPgmTime;
    nResult_via_iteration = fib_via_iteration(i);
    nElapsedTime_iteration = nPgmTime - nElapsedTime_iteration;


    writeDebugStreamLine("%3d: %9d %7d msec  %7d msec", i, nResult_via_recursion, nElapsedTime_recursion, nElapsedTime_iteration);
    wait1Msec(1);
  }
}
