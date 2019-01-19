// red and green LEDs flash alternatively

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

    P1OUT_bit.P0 = 0xFF; //Turn on red LED
    P1OUT_bit.P6 = 0x00; //Turn off green LED
    delay(50000);
    P1OUT_bit.P0 = 0x00; //Turn off red LED
    P1OUT_bit.P6 = 0xFF; //Turn on green LED
    delay(50000);
   }
  }
