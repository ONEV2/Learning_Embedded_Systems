/*
 * USART code 
 * Created by- Prakhar Agrawal
 * Date - 25-04-22
 * Time - 13:43
 */
 
#ifndef F_CPU
#define F_CPU 16000000UL 
#endif

#include <avr/io.h>
#include <util/delay.h>

#define USART_BAUDRATE 9600
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)

void USART_init(int16_t BAUD_RATE){
    UCSR0B |= (1<<RXEN0) | (1<<TXEN0); //Turn on Transmission and Reception
    UCSR0C |= (1<<USBS0)| (1<<UCSZ01)| (1<<UCSZ00); ///Use 8 bit char size
    UBRR0L = BAUD_PRESCALE;  //load lower 8 bits
    UBRR0H = BAUD_PRESCALE >> 8; //load upper 8 bits
  }

void USART_TX(char data){
  while(!(UCSR0A & (1<<UDRE0)));  //wait for transmit buffer to be empty
  UDR0 = data; //Tx buffer will get wriUSARTen
  }

char USART_RX(){
  while(!(UCSR0A & (1<<RXC0))); //wait till data is received
  return UDR0;
  }

void setup(){}

void loop() {
  // put your main code here, to run repeatedly:
  USART_init(9600);
  char ch = USART_RX();
  USART_TX(ch);
  _delay_ms(100);

}
