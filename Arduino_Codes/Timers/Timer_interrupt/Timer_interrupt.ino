/*
 * Timer Interrupt.c
 * Created by - Prakhar Agrawal
 * Date - 30-04-22
 * Time - 10:56
 */
#include <avr/io.h>
#include <avr/interrupt.h>

ISR(TIMER0_OVF_vect){
  PORTB = ~PORTB; 
  TCNT0 = 0x64;
  }
void setup() {
  // put your setup code here, to run once:
  DDRB=0xFF;            /*make port B as output*/
  sei();
  TIMSK0=(1<<TOIE0);       /*Enable Timer0 overflow interrupts */
    
  TCNT0 = 0x64;         /*load TCNT0, count for 10ms*/
  TCCR0B = (1<<CS02) | (1<<CS00);  /* start timer0 with /1024 prescaler*/
}

void loop() {
  
  while(1);
}
