#include <msp430.h>
#include "stateMachine.h"
#include "switches.h"
#include "buzzer.h"
#include "led.h"

void state_advance(){
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
    nokiaSong();
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
