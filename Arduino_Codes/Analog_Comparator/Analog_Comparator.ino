/*
 * Analog Comparator file
 * Created by - Prakhar Agrawal
 * Date - 02-05-22
 * Time - 9:50
 */
 
#include <avr/io.h>

void Analog_Comparator_init(void){
  ADCSRB &= ~(1<<ACME); //set AIN1 for -ve input
  ACSR = (1<<ACIE); //enable comparator interrupt
  }

ISR(ANALOG_COMP_vect){
  PORTB = ~PORTB; //toggle the led
  cli();
  }

void setup() {
  // put your setup code here, to run once:
  DDRB = (1<<PB5); //set pb5 as output 
  PORTB = (1<<PB5);
}

void loop() {
  // put your main code here, to run repeatedly:
  Analog_Comparator_init();
  sei();
}
