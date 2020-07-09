#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"
#include "stateMachine.h"

char state, switch_state_down, switch_state_changed; /* effectively boolean */

static char switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);	/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);	/* if switch down, sense up */
  return p2val;
}

void switch_init()			/* setup switch */
{  
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE |= SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_update_interrupt_sense();
  switch_interrupt_handler();
}

void switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();
  if (p2val & SW1 ? 0 : 1){
    state = 1;
    //stateCall(1);
  }
  else if (p2val & SW2 ? 0 : 1){
    state = 2;
    // stateCall(2);
  }
  else if (p2val & SW3 ? 0 : 1){
    state = 3;
    // stateCall(3);
  }
  else if (p2val & SW4 ? 0 : 1){
    state = 4;
    // stateCall(4);
  }
  state_advance();
}
/*
void stateCall(int state) {
  switch(state){
  case 1:
    randomSong();
    greenLights();
    break;
  case 2:
    sharkSong();
    dimBlink();
    break;
  case 3:
    redLights();
    greenLights();
    break;
  case 4:
    spongebobSong();
    bothLights();
    break;
  default:
    break;
  }
}
*/
