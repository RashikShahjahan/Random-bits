//Turns on red LED for 3 seconds after button is pressed

#include "io430.h"



#define ON  1

#define OFF 0



#define RED_LED   P1OUT_bit.P6

#define GREEN_LED P1OUT_bit.P0

#define BUTTON    P1IN_bit.P3

// creates a delay of n number of clock cycles.

void delay(unsigned long d)

{

  while (--d);

}


void main (void)

{

  // Stop watchdog timer

  WDTCTL = WDTPW + WDTHOLD;



  // setup port

   P1DIR = BIT6;  // P1.0 is output





  while(1)

   {

       if (!BUTTON) 
       {
          RED_LED = ON;
          delay(500000);

       }
       else
       {

          RED_LED = OFF;


       }
     }

}
