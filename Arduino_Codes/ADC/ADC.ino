/*
 * ADC.c file
 * Created by - Prakhar Agrawal
 * Time - 21:56 
 * Date - 29-04-22
 */

#include <avr/io.h>
#include <util/delay.h>

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

void ADC_init(void){
  DDRC = 0x00;  // Set ADC port to input
  ADCSRA = (1<<ADEN) | (1<<ADIF)| (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0); //set prescaler to 128
  ADMUX = (1<<REFS1) | (1<<REFS0);  //set voltage reference to AVcc=5v,select channel 0
  }

int ADC_Read(char channel){
  ADMUX |= (channel & 0x0f);
  int lower_byte;
  int upper_byte;
  ADCSRA |= (1<<ADSC);  //ADC start conversion
  while(ADCSRA & (1<<ADIF));  //wait for the conversion to complete
  _delay_ms(1);
  lower_byte = ADCL;
  upper_byte = (ADCH<<8); //read upper 8 bits [2 in our case]
  int data = upper_byte + lower_byte;
  return data;
  
  }

void setup() {
  Serial.begin(9600);
  Serial.println("ADC code");
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  ADC_init();
  int val = ADC_Read(0);
  Serial.println(val);
  _delay_ms(10);

}
