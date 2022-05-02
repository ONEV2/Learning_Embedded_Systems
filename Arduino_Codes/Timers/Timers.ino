/*
 * Timer.c file
 * Created by - Prakhar Agrawal
 * Time - 00:42
 * Date - 30-04-22
 */
 
#include <avr/io.h>

void Timer0_delay(void){
  TCCR0B = (1<<CS02)| (1<<CS00) ; //prescaler set to 1024
  TCCR0A &= ~((1<<WGM00) | (1<<WGM01) | (1<<WGM02));  //set mode of operation to normal mode
  TCNT0 = 0x64; // for a delay of 10ms
  while(!(TIFR0 & (1<<TOV0))); //wait for the overflow flag to bet set
  TCCR0B = 0x00;  //no clock source,i.e stop the timer
  TIFR0 = (1<<TOV0);  //clear the overflow flag
  }
void setup() {
  // put your setup code here, to run once:
  DDRB = 0xff;
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  PORTB = 0x00;
  Timer0_delay();
  PORTB = 0xff;
  Timer0_delay();
}
