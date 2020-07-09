#include <msp430.h>
#include "stateMachine.h"
#include "switches.h"
#include "buzzer.h"
#include "led.h"

void state_advance(){
  switch(state){
  case 0:
    beep();
    break;
  case 1:
    randomSong();
    greenLights();
    state = 0;
    break;
  case 2:
    sharkSong();
    dimBlink();
    state = 0;
    break;
  case 3:
    nokiaSong();
    redLights();
    greenLights();
    state = 0;
    break;
  case 4:
    spongebobSong();
    bothLights();
    state = 0;
    break;
  default:
    break;
  }
}
