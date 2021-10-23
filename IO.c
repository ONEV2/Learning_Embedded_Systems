// Author- Prakhar Agrawal
// Date- 23/10/21

#ifndef F_CPU
#define F_CPU 8000000L
#endif

#include <avr/io.h>
#include <util/delay.h>

int main(){
  DDRB = 0xFF;  //all port B pins as output
  unsigned int pin = 0x20;  //pin6 in port B(PB6)
  PORTB |= (1<<pin); //turn on pin6 in portB
  delay_ms(100);
  PORTB |= 0x00;
  
return 0;
}
