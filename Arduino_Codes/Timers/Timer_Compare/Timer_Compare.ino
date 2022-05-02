/*
 * Clear timer on compare match
 * Created by - Prakhar Agrawal
 * Time - 14:55
 * Date - 30-04-22
 */

#include <avr/io.h>


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  DDRD = (1<<PD6);  //set PD6 pin as output pin
}

void loop() {
  // put your main code here, to run repeatedly:
  TCCR0A = (1<<COM0A0);
  TCCR0B = (1<<CS00);
  OCR0A = 100;  //compare value
  while ((TIFR0&(1<<OCF0A)) == 0);
  uint8_t pinVal;
  if(PD6>0)
    pinVal = 1;
  else
    pinVal = 0;
  Serial.println(pinVal);
  delay(1000);
  Serial.println(0);
  while(1);
} 
