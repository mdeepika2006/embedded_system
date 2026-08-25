#include <reg51.h>

sbit PWM = P1^0;

unsigned char count = 0;
unsigned char duty = 100;   // Change this value (0-200)

void timer0_ISR(void) interrupt 1
{
    TH0 = 0xFC;
    TL0 = 0x66;

    count++;

    if(count < duty)
        PWM = 1;
    else
        PWM = 0;

    if(count >= 200)
        count = 0;
}

void main()
{
    TMOD = 0x01;   // Timer0 Mode 1 (16-bit)

    TH0 = 0xFC;
    TL0 = 0x66;

    IE = 0x82;     // EA = 1, ET0 = 1
    TR0 = 1;       // Start Timer0

    while(1);
}