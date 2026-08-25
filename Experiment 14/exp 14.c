#include <reg51.h>
#include <stdio.h>

void main(void)
{
    SCON = 0x50;   // UART mode 1, 8-bit, receiver enabled
    TMOD = 0x20;   // Timer 1, mode 2, auto-reload
    TH1 = 0xFD;    // 9600 baud rate for 11.0592 MHz crystal
    TR1 = 1;       // Start Timer 1
    TI = 1;        // Set TI for first character transmission

    while(1)
    {
        printf("Hello World!\r\n");
    }
}