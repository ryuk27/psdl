#include <p18f4550.h>
#include <stdio.h>
#include "LCD_SIT.h"
const unsigned char LCD_Data1[]={"ADC Value="};
void DisplayResult(unsigned short hexVal);
void main()
{
unsigned char z=0,hexVal;
// TRISEbits.RE1 = 1; //ADC channel 6 input
TRISEbits.RE2 = 1; //ADC channel 7 input
Init_LCD();
ADCON1=0x0E; // Voltage Reference Configuration bit ? VSS, A/D
Port Configuration Control bits -DDDDAAAAAAAA
ADCON2=0xAE; //A/D Result Format Select bit - Right justified,
A/D Acquisition Time Select bits - 12 TAD, A/D Conversion Clock Select
bits -FOSC/64
lcdcmd(0x80);
MSdelay(50);
for (z=0;z<10;z++)
{
lcddata(LCD_Data1[z]);
MSdelay(50);
}
while(1)
{
ADCON0bits.ADON = 1; //A/D On bit- on
ADCON0bits.CHS = 0x07; //Analog Channel Select bits? ch n0-
7(ADC1)
ADCON0bits.GODONE = 1; //A/D Conversion Status bit --
conversion in progress
while(ADCON0bits.GO_DONE == 1 );
ADCON0bits.ADON = 0; //A/D On bit- off
DisplayResult(ADRES);
}
}
void DisplayResult(unsigned short hexVal)
{
unsigned char i,text[16];
unsigned short tempv;
tempv = hexVal;
hexVal = (5200/1024)*tempv;
lcdcmd(0x8A);
MSdelay(50);
sprintf(text,"%04dmv",hexVal);
for(i=0;i<6;i++)
{
lcddata(text[i]);
MSdelay(50);
}
lcdcmd(0xC0);
MSdelay(50);
for(i=0;i<10;i++)
{
if(tempv & 0x200)
{
lcddata('1');
MSdelay(50);
}
else
{
lcddata('0');
MSdelay(50);
}
tempv<<=1;
}
}
