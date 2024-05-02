/*Calculations:
Fosc = 20MHz

  PWM Period = [(PR2) + 1] * 4 * TMR2 Prescale Value / Fosc
  PWM Period = 200us
  TMR2 Prescale = 4
  Hence, PR2 =  249 or 0xF9

  Duty Cycle = 10% of 200us
  Duty Cycle = 20us
  Duty Cycle = (CCPR1L:CCP1CON<5:4>) * TMR2 Prescale Value / Fosc
  CCP1CON<5:4> = <1:1>
  Hence, CCPR1L = 24 or 0x18
 */

#include<p18f4550.h>
unsigned char count=0;
bit TIMER,SPEED_UP;

void timer2Init(void)
{
    T2CON   =   0b00000001;   //Prescalar = 4; Timer2 OFF
    PR2     =   0xF9;                   //Period Register
}

void Interrupt_Init(void)
{
INT1IE  =   1;     //Enable external interrupt INT1
    INTEDG1 =   0; //Interrupt on falling edge
    GIE     =   1;      // Enable global interrupt
}
void interrupt timerinterrupt(void)
{
if (INT1IF)                        // If the external interrupt flag is 1, do .....
    {
INT1IF  =   0;                  // Reset the external interrupt flag
if(SPEED_UP)
        {
if(count < 8)
            {
count++;
                CCPR1L = 0x18 + (count * 25);      //Increment duty cycle
            }
else SPEED_UP = 0;
        }
else
        {
if(count > 0)
            {
count--;
                CCPR1L = 0x18 + (count * 25);     //Decrement duty cycle
            }
else SPEED_UP = 1;
        }
    }
}
void main(void)
{
    TRISBbits.TRISB1    = 1;            	// interrupt pin as input
    TRISCbits.TRISC2    = 0;            	//CCP1 pin as output
CCP1CON  =   0b00111100;       	//Select PWM mode; Duty 					cycle LSB CCP1CON<4:5> = 					<1:1>
    CCPR1L   =   0x18;                  	//Duty cycle 10%
timer2Init();                       		//Initialise Timer2
Interrupt_Init();                   		//Initialise interrupts
    SPEED_UP = 1;
    TMR2ON = 1;                         		//Timer2 ON
while(1);                           		//Loop forever
}
