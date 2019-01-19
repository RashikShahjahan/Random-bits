
//The code causes the LEDs on the microcontroller to blink rapidly

#include "io430.h"

// creates a delay of n number of clock cycles.
void delay(unsigned long d)

{

  while (--d);

}

int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;

  P1DIR = 0xFF;   // setup PORT1 as output

  while (1)
  {
    P1OUT = 0xFF; //Turn on LEDs
    delay(50000);
    P1OUT = 0x00; //Turn off LEDs
    delay(50000);
  }
}
