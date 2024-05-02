#define Dispselection 0x38
#define DisplayonCurserblinking 0x0e
#define Cleardisplay 0x01
#define Shiftright 0x06
void Init_LCD(void);
void lcdcmd(unsigned char value);
void lcddata(unsigned char value);
void MSdelay(unsigned int itime);
void LCDDisplayStr(unsigned char *String);
