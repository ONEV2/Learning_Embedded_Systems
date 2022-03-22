/*
* Created on 22/03/22
* Author : Prakhar Agrawal
* Pin change Interrupt Example
*/

#include <avr/io.h>
#inlcude <util/delay.h>
#include <interrupt.h>

ISR(PCINT2_vect){
  while(int i=0;i<7;i++){
    PORTD^= (i<<LED);
  }
}

void init_pinchanage_Interrupt(void){
  PCICR |= (1<<PCIE2); // enable all the pinD pins as interrupt
  PCMSK2 |= (1<<PD2); // PIN D2 is set as interrupt pin
  sei();
}

int main(void){
  LED = PD4;
  while(1){
  }
  return 0;
}
