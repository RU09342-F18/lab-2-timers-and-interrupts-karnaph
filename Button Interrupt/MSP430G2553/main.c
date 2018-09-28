#include <msp430.h>

void main(void) {
    WDTCTL = WDTPW | WDTHOLD;// Stop watchdog timer

    P1DIR |= BIT0; //set Port 1.0 output (LED)
    P1DIR &= ~BIT3; //set Port 1.1 input (pushbutton)
    P1REN|= BIT3; //enable pull-up resistor on
    P1OUT|= BIT3; //Input mode pull down

    P1IE |= BIT3; //enable the interrupt on Port 1.1
    P1IES |= BIT3; //set as falling edge
    P1IFG &= ~BIT3; //clear interrupt flag

    //enter LPM4 mode and enable global interrupt
    _BIS_SR(LPM4_bits + GIE);
}

//Port 1 ISR
#pragma vector=PORT1_VECTOR
    __interrupt void PORT_1(void)
    {
        P1OUT ^= BIT0;
        P1IFG &= ~(BIT3);
    }
