/**************************\
|*  ROBOTC for Beginners  *|
|*  Moving in a Square    *|
\**************************/


task main()
{
  robotType(recbot);  // We are using the recbot.

  forward(63);        // Move forward at speed 63.      >
  wait(1.5);          // Wait 1.5 seconds.              |
  pointTurn(right);   // Turn right, in place.          |
  wait(0.4);          // Wait for 0.4 seconds.          |

  forward(63);        // Move forward at speed 63.      _ _ _
  wait(1.5);          // Wait 1.5 seconds.              |     v
  pointTurn(right);   // Turn right, in place.          |
  wait(0.4);          // Wait for 0.4 seconds.          |

  forward(63);        // Move forward at speed 63.      _ _ _
  wait(1.5);          // Wait 1.5 seconds.              |     |
  pointTurn(right);   // Turn right, in place.          |     |
  wait(0.4);          // Wait for 0.4 seconds.          |    <|

  forward(63);        // Move forward at speed 63.      _ _ _
  wait(1.5);          // Wait 1.5 seconds.              |     |
  pointTurn(right);   // Turn right, in place.          |     |
  wait(0.4);          // Wait for 0.4 seconds.          ^_  _ |
}
