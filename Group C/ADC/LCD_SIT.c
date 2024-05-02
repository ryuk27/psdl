#include <p18f4550.h>
#include "LCD_SIT.h"
#define en LATCbits.LC1
#define rs LATCbits.LC0
#define LCDPORT LATB
void Init_LCD(void)
{
TRISB = 0x00; //set data port as output
TRISC=0x00;
TRISCbits.RC0 = 0; //EN pin
TRISCbits.RC1 = 0; // RS pin
en=0;
MSdelay(50);
lcdcmd(Dispselection); //2line and 5X7 matrix
MSdelay(50);
lcdcmd(DisplayonCurserblinking); //Display on, Curser blinking
MSdelay(50);
lcdcmd(Cleardisplay); //Clear display screen
MSdelay(50);
lcdcmd(Shiftright); //Shiftcursor to right
MSdelay(50);
}
void lcdcmd(unsigned char value)
{
LCDPORT = value;
rs = 0;
en = 1;
MSdelay(1);
en = 0;
return;
}
void lcddata(unsigned char value)
{
LCDPORT = value;
rs = 1;
en = 1;
MSdelay(1);
en = 0;
return;
}
void MSdelay(unsigned int itime)
{
unsigned int i,j;
for(i=0;i<itime;i++)
for(j=0;j<1200;j++);
}
void LCDDisplayStr(unsigned char *String)
{
while(*String)
{
lcddata(*String);
MSdelay(50);
String++;
}
}
