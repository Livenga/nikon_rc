#include <xc.h>

#include "../include/init.h"
#include "../include/common.h"


#define LED    PORTAbits.RA0
#define SW     PORTBbits.RB0
#define SW_DIR TRISBbits.TRISB0

/** void - IR リモコンのパルス照射 */
void
nikon_pulse(void);


/** void interrupt - 割り込み関数 */
void interrupt
isr(void)
{ /* {{{ */
  INTCONbits.GIE = 0;

  if(INTCONbits.INTF) {
    if(SW == 0) {
      nikon_pulse();
      nikon_pulse();

      __delay_ms(100);
    }

    INTCONbits.INTF = 0;
  }

  INTCONbits.GIE  = 1;
} /* }}} */

void
main(void)
{
  CMCON   = 0b00000111;

  INTCON  = 0b11010000;
  //INTCON  = 0b00000000;
  PIE1    = 0b00000000;

  TRISA  = 0b00000000;
  TRISB  = 0b00000000;

  PORTA  = 0b00000000;
  PORTB  = 0b00000000;

  OPTION_REG = 0b00000000;
  //OPTION = 0b00000000;

  SW_DIR = 1;

  while(1) {
    NOP();
  }


  return;
}


#define _CLOCK_PULSE()\
  LED = 1;\
  __delay_us(26);\
  LED = 0;\
  __delay_us(26)

/** void - IR リモコンのパルス */
void
nikon_pulse(void)
{ /* {{{ */
  unsigned char i;

  for(i = 0; i < 76; i++)
    _CLOCK_PULSE();

  LED = 0;
  __delay_ms(28);

  for(i = 0; i < 15; i++)
    _CLOCK_PULSE();

  LED = 0;
  __delay_ms(1);
  __delay_us(580);

  for(i = 0; i < 15; i++)
    _CLOCK_PULSE();

  LED = 0;
  __delay_ms(3);
  __delay_us(580);


  for(i = 0; i < 15; i++)
    _CLOCK_PULSE();
  //LED = 0;
} /* }}} */
