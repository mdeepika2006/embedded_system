#include <reg51.h>
#include <stdio.h>

void serial_ISR(void) interrupt 4
{
    char ch;

    if(RI == 1)
    {
        RI = 0;
        ch = SBUF;

        printf("\r\nINTERRUPT RECEIVED: ");
        printf("%c\r\n", ch);
    }
}

void delay(void)
{
    unsigned int i;

    for(i = 0; i < 50000; i++);
}

void main(void)
{
    SCON = 0x50;
    TMOD = 0x20;

    TH1 = 0xFD;
    TL1 = 0xFD;

    TR1 = 1;

    IE = 0x90;

    TI = 1;

    while(1)
    {
        printf("Hello World\r\n");
        delay();
    }
}