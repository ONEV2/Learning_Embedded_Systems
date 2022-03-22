/*
Flash led at a fixed rate, interrupt is enabled when button is pressed
Created by - Prakhar Agrawal
Date - 21-03-22
interrupt.c
*/

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#ifndef F_CPU
#define F_CPU 16000000  //external clock at 16Mhz
#endif


ISR(INT0_vect){
  //if button is pressed
  PORTD |= (1<<LED);
  //else
  PORTD &= ~(1<<LED);
}

void init_Interrupt(void){
  EMISK |= (1<<INT0); // Enabling external pin interrupt
  EICRA |= (1<<ISC00);  //Any logic change of INT1 generates an interrupt request
}

void main(){
  DDRD = 0xff;  //set all pins as output pins
  LED = PD4;
  init_Interrupt();
  while(1){ //blink led untill push button is pressed
    _delay_ms(200);
    PORTD ^= (1<<LED);
  }
}
