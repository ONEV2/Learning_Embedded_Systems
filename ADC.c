/*
 * Analog to Digital Converter
 *
 * Created: 25-10-2021 12:35:33 PM
 * Author : prakhar agrawal
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

#ifndef F_CPU
#define F_CPU 8000000UL
#endif

void ADC_init(){
	ADCSRA |= (1<<ADEN) | (1<<ADIE) | (1<<ADPS0) | (1<<ADPS1) | (1<<ADPS2); // prescalar =  128
	ADMUX |= (1<<REFS0);	//REFS1 = 0 and REFS0 = 1 i.e- AVcc with external capacitor at Aref pin
	
}

int ADC_read(int channel){
	int lbyte,ubyte;	//two variables for storing values from ADCL and ADCH 8-bit registers
	unsigned long data;	//variable to display data
	ADMUX |= (channel & 0x0f); // select input channel 0-8 and set the MUX0:3 bits in ADMUX register
	ADCSRA |= (1<<ADSC);	//Start conversion
	while(!(ADCSRA & (1<<ADIF)));	//Wait till the conversion is complete and the interrupt flag is set
	_delay_ms(10);
	ADCSRA = (1<<ADIF);	//Clear ADIF flag
	lbyte=ADCL;
	ubyte=ADCH;
	data=lbyte+ubyte;	//"ADC" variable (AVR-GCC defined variable) Contains the whole 10 bit ADC result
	return data;
	
}


int main(void)
{
    ADC_init();
	ADC_read(channel);	//Replace channel with 0-8;
}

