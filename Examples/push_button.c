#include <avr/io.h>
#include <util/delay.h>

int main(void){
  DDRB |= 0xff; //portb all pin as output
  PORTD |= (1<<PD2);  //port D pin 2 is input(pull ups enabled)
  while(1){
    if((PIND & (1<<PD2))==0){ //push button is pulling the circuit to ground
      PORTB = 0b00111100; //button is pressed
    }
    else{
      PORTB = 0b11000011; //nutton is not pressed
    }
  }
  return 0;
}
