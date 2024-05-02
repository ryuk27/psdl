#include<stdio.h>
#include<stdlib.h>
#include<pic18f4550.h>
void main(void)
{
int i, dividend, divisor, quotient, remainder;
dividend=0x07;
    divisor=0x02;
    quotient=0;
remainder=0;
for(i=0; dividend>=divisor;i++)
    {
        dividend = dividend-divisor;
quotient = quotient+1;
    }
remainder =dividend;
    TRISB=0;
    PORTB=quotient;
}
