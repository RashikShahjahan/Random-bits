// Delay function which uses the hardware timer

#include "io430.h"

void delay(unsigned int d)

{

  TA0CCR0 = d;

  // Enables counting from zero to TA0CCR0
  TA0CTL_bit.MC1 = 0;
  TA0CTL_bit.MC0 = 1;

 //Terminates when TAIFG is True, meaning TA0R = TA0CCR0
  while(TA0CTL_bit.TAIFG == 0);

  //Stops counting
  TA0CTL_bit.MC1 = 0;
  TA0CTL_bit.MC0 = 0;

}

int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;

  P1DIR = 0xFF; // setup PORT1 as output

  P2SEL = 0;
  P2SEL2 = 0;

   //Selects  SMCLK to be the clock source
   TA0CTL_bit.TASSEL1 = 1;
   TA0CTL_bit.TASSEL0 = 0;

   //No reduction in clock frequency
   TA0CTL_bit.ID1 = 0;
   TA0CTL_bit.ID0 = 0;

   // Tests the hardware delay
   while(0){
          P1OUT = 0x00;
          delay(50000);
          P1OUT = 0xFF;
}
  }
