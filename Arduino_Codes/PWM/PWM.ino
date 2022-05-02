/*
 * PWM.c file
 * Created by - Prakhar Agrawal
 * Date - 01-05-22
 * Time - 17:17
 */

#include <avr/io.h>


void PWM_init(void){
  TCCR0A = (1<<COM0A1)|(1<<WGM01)|(1<<WGM00); //set to fast PWM with clear OC0A on upcounting
  TCCR0B = (1<<CS00); //set prescaler to 1
  }
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  DDRB = (1<<PD6);  //set pin 6 as output pin
  OCR0A = 0x7F;
}

void loop() {
  // put your main code here, to run repeatedly:
  PWM_init();
  Serial.println(PD6);
}
