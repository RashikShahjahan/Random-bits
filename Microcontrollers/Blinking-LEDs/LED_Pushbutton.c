//alternates between LEDs after button is pushed

#include "io430.h"



#define ON  1

#define OFF 0



#define RED_LED   P1OUT_bit.P6

#define GREEN_LED P1OUT_bit.P0

#define BUTTON    P1IN_bit.P3



void main (void)

{

  // Stop watchdog timer

  WDTCTL = WDTPW + WDTHOLD;



  // setup port

  P1DIR_bit.P0 = BIT0;  // P1.0 is output
  P1DIR_bit.P6 = BIT0;




  while(1)

   {

       if (BUTTON)
       {
          RED_LED = OFF;
          GREEN_LED = ON;
       }
       else
       {
          RED_LED = ON;
          GREEN_LED = OFF;

       }
     }

}
