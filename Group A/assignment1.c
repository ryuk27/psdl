#include<stdio.h>
#include<stdlib.h>
#include<pic18F4550.h>
void main(void)
{
int i, j, x; 
TRISB=0;  
LATB=0;
i=0x04;
j=0x05;
x=i+j; 
PORTB=x;  
PORTC=i;  
PORTD=j;
}
