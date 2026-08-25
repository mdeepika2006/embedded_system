#include <reg51.h>

void main(void)
{
    unsigned char hexa = 123;
    unsigned char hundreds, tens, units;

    units = hexa % 10;
    hexa = hexa / 10;

    tens = hexa % 10;
    hexa = hexa / 10;

    hundreds = hexa;

    P0 = units;
    P1 = tens;
    P2 = hundreds;

    while(1);
}