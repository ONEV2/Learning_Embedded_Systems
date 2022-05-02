/*
 * Timer Input capture file
 * Created by - Prakhar Agrawal
 * Time - 12:58
 * Date - 30-04-22
 */
#include <avr/io.h>

unsigned int t;

void IO_init(void){
  DDRB = 0xff;
  DDRC = 0xff;
  PORTD = 0xff;
  }

void Timer1_init(void){
  TCCR1A = 0x00;
  TCCR1B = (1<<ICES1) | (1<<CS10);  //rising edge will trigger the capture, prescaler to 1
  }

void setup() {
  // put your setup code here, to run once
}

void loop() {
  while(!(TIFR1 & (1<<ICF1)));  //monitor for capture
  t = ICR1; //when the edge is captured, the value of TCNT1 is stored in ICR1
  TIFR1 = (1<<ICF1); //clear capture flag
  
  while(!(TIFR1 & (1<<ICF1)));//monitor for next capture in the rising edge
  t = ICR1 - t; // period  = recent capture - previous capture
  
  PORTB = t;
  PORTC = t>>8;
}
