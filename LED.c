/*
* Blink_Led.c ; Serial_parallel_shift_led.c
* Created: 19/05/21 12:44:00
* Author: Prakhar Agrawal
* Description: This sketch contains basic code for blinking LED in atmega328p by directly accessing registers.
*/

#ifndef F_CPU
#define F_CPU 16000000UL  //16mhz clock speed
#endif

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
  DDRB = 0xFF; //Make port c as output ports
  PORTB = 0x01; //turn on 1st bit and keep other bits as 0
  //------------Blink LED-------------//
  while(1)
    PORTB=0xFF; //Turn on all port c led's
    _delay_ms(1000);
    PORTB=0x00; //Turn of all the led's
    _delay_ms(1000);
//----------Serial_parallel_shift_led-----------//
  while(1)
    _delay_ms(1000); //This delay is kept since we initially set 1st bit as 1,if there is no delay,when the code runs 1st and 2nd led will turn on at some micro second delay
    for(int i=0;i<7;i++)  //loop runs 7 times turning all led's(2-8) one by one
      PORTB |= (PORTB<<1);  //Turn on all the led's one-by-one
      _delay_ms(1000);
    for(int i=0;i<8;i++)  //loop runs 8 times turning off all leds(8-1) one by one
      PORTB &= (PORTB>>1);
      _delay_ms(1000);
return 0;
}
