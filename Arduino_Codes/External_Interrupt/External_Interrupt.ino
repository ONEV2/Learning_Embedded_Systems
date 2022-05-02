/*
 * External_Interrupts file 
 * Created by - Prakhar Agrawal
 * Time - 20:19
 * Date - 1/05/22
 */
 
#include <avr/io.h>

void External_Interrupt_init(void){
  EICRA = (1<<ISC00); //Any logical change on INT0 generates an interrupt request
  EIMSK = (1<<INT0);  // Enable external pin interrupt
  }

ISR(INT0_vect){
  PORTB = ~PORTB; //toggle LEDSTATE state
  int val = PIND & (1 << PIND2);
  Serial.println(val);  //debugging
  _delay_ms(50);  // To avoid debouncing
  cli();
  }
  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  DDRB = 0xff;  //set Port B as output
  DDRD = 0x00;  //set Port D as input
}

void loop() {
  // put your main code here, to run repeatedly:
  External_Interrupt_init();
  sei();  //enable global interrupt
  PORTB &= ~(1<<PB5);
}
