#include <p18f4550.h>
#define en LATCbits.LC1
#define rs LATCbits.LC0
#define LCDPORT LATB
const unsigned char
LCD_Data1[]={"Ram"};
const unsigned char
LCD_Data2[]={"Vinchurkar"};

void lcdcmd(unsigned char value);
void lcddata(unsigned char value);
void MSdelay(unsigned int itime);

void main()
{
    unsigned char z=0;
    TRISB=0;
    TRISC=0;
    en=0;
    MSdelay(50);
    lcdcmd(0x38);
    MSdelay(50);
    lcdcmd(0x0e);
    MSdelay(50);
    lcdcmd(0x01);
    MSdelay(50);
    lcdcmd(0x06);
    MSdelay(50);

    while(1)
    {
        lcdcmd(0x86);
        MSdelay(50);
        for (z=0;z<3;z++)
        {
            lcddata(LCD_Data1[z]);
            MSdelay(50);
        }
        lcdcmd(0xC4);
        MSdelay(50);
        for (z=0;z<10;z++)
        {
            lcddata(LCD_Data2[z]);
            MSdelay(50);
        }
    }
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
