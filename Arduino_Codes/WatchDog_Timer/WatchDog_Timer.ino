/*
 * Watchdog timer file
 * Created by - Prakhar Agrawal
 * Time - 11:12
 * Date - 2/05/22
 */
 
#include <avr/io.h>

void WDT_system_resest(void){
  WDTCSR |= (1<<WDCE)|(1<<WDE); //change enabled
  WDTCSR = (1<<WDE) |(1<<WDP2) | (1<<WDP1) | (1<<WDP0); //System reset is set to 2 sec
  }

void WDT_interrupt_init(void){
  WDTCSR |= (1<<WDCE)|(1<<WDE); //change enabled
  WDTCSR = (1<<WDIE)|(1<<WDP2) | (1<<WDP1) | (1<<WDP0); //Interrupt call after every 2 sec
  }

ISR(WDT_vect){
  PORTB ^= (1<<PB5);
  cli();
  }

void WDT_disable(void){
  MCUSR &= ~(1<<WDRF);  //clear watchdog system reset flag
  WDTCSR |= (1<<WDCE) | (1<<WDE); //
  WDTCSR = 0x00;  //turn of Watch dog timer
  }

void setup() {
  // put your setup code here, to run once:
  WDT_disable();  // if watchdog is not being used, its better to initialise with a watchdog disable routine to avoid any unwanted eternal loops
  DDRB = (1<<PB5);  //set as output pin
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sei();
  //WDT_system_reset();
  WDT_interrupt_init();
  //PORTB ^= (1<<PB5); //toggle led 
  while(1);
}
