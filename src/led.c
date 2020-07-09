#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "stateMachine.h"

void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  switch_state_changed = 1;
}

void greenLights(){
  for(int i = 0; i < 10; i++){
    P1OUT = LED_GREEN;
    __delay_cycles(800000);
    P1OUT = !LED_GREEN;
    __delay_cycles(800000);
  }
}

void redLights(){
  for(int i = 0; i < 10; i++){
    P1OUT = LED_RED;
    __delay_cycles(800000);
    P1OUT = !LED_RED;
    __delay_cycles(800000);
  }
}

void bothLights(){
  for(int j = 0; j < 10; j++){
    P1OUT = LED_RED;
    __delay_cycles(800000);
    P1OUT = LED_GREEN;
    __delay_cycles(800000);
    P1OUT = !LED_RED;
    __delay_cycles(800000);
    P1OUT = !LED_GREEN;
    __delay_cycles(800000);
  }
}
void dimLights(){
  for(int j= 0; j <10000; j++){
    P1OUT = LED_RED;
    P1OUT = LED_GREEN;
    P1OUT = !LED_RED;
    P1OUT = !LED_GREEN;
  }
}

void dimBlink(){
  for(int i = 0; i < 20; i++){
    dimLights();
    __delay_cycles(2000000);
    P1OUT = !LED_RED;
    P1OUT = !LED_GREEN;
  }
}
void led_update(){
  //  if (switch_state_changed) {
  // char ledFlags = 0; /* by default, no LEDs on */
  switch(state) {
  case 1:
    redLights();
    randomSong();
    greenLights();
    break;
  case 2:
    redLights();
    greenLights();
    break;
  case 4:
    greenLights();
    break;
  case 3:
    redLights();
    greenLights();
    bothLights();
    break;
  default:
    break;
    // turn LED off; break;
		       
    // ledFlags |= switch_state_down ? LED_GREEN : 0;
    // ledFlags |= switch_state_down ? 0 : LED_RED;

    P1OUT &= (0xff - LEDS); // clear bits for off leds
    // P1OUT |= ledFlags;         // set bits for on leds
  }
  // switch_state_changed = 0;
}

