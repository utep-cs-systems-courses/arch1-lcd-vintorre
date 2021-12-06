#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

void buzzer_init(){
  timerAUpmode();
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;
}

void buzzer_set_period(short cycles){
  CCR0 = cycles;
  CCR1 = cycles >> 1;
}

static int counter = 0;

void song(){
  switch(counter){
  case 0: buzzer_set_period(750); counter++; break;
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
  case 9: buzzer_set_period(950); counter++; break;
  case 10: buzzer_set_period(500); counter++; break;
  case 11:
  case 12:buzzer_set_period(630); counter++; break;
  case 13:
  case 14:buzzer_set_period(560); if(counter == 14){ counter = 0;} else {counter++;} break;
  }
}
