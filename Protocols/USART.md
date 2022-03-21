```
/*
 * Serial_communication.c
 * MCU:Atmega328p
 * Created: 28-04-2021
 * Author : prakhar agrawal
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL //clock speed with external crystal of 16 MHz
#endif
```
## USART Data Register
### UDR(read)
|RXB7|RXB6|RXB5|RXB4|RXB3|RXB2|RXB1|RXB0|
| ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- |
### UDR(write)

|TXB7 |TXB6 |TXB5 |TXB4 |TXB3 |TXB2 |TXB1| TXB0|
| ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- |

### When we write to the UDR register Tx buffer will get written and when we read from this register Rx buffer will get read.

### USART Status Register 
### USART status register A
|RXC |TXC |UDRE |FE |DOR |PE |U2X |MPCM|
| ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- |
* ### RXC(USART Receive Complete) bit is set when there is unread data in UDR
* ### TXC(USART Transmit Complete) bit is set when the entire frame is shifted and there is no new data currently present in UDR.
* ### UDRE(USART Data Register Empty) bit is set when buffer is empty i.e transmit buffer(UDR) is ready to receive new data.
* ### FE(Frame Error) is set if the next character in the receive buffer had a frame error when received.
* ### DOR(Data overRun) bit is set if data Overrun condition is detected.A data Overrun occurs when the receiver is full and the new character is waiting in the Receive shift register.
* ### PE(Parity Error) is set if the next character in the receive buffer had a parity error 
* ### U2X:Doubles the USART transmission speed
* ### MPCM:Multi Processor Communication mode

### USART status register B
|RXCIE |TXCIE |UDRIE |RXEN |TXEN |UCSZ2 |RXB8 |TXB8|
| ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- |
* ### RXCIE(RX Complete Interrupt Enable):Writing one to this bit enables interrupt on the RXC flag.
* ### TXCIE(TX Complete Interrupt Enable):Writing one to this bit enables interrupt on the TXC flag.
* ### UDRIE(USART Data Register Empty Interrupt Enable):Writing one to this bit enables interrupt on the UDRE flag.
* ### RXEN(Receive Enable):Writing one to this bit enables the USART receiver.
* ### TXEN(Transmit Enable):Writing one to this bit enables the USART transmitter.
* ### UCZ2(Character size):The UCSZ2 along with UCSZ1:0 bit in the UCSRC sets the number of data bits in a frame.
* ### RXB8 and TXB8 are the 9th data bit of the character(transmitter or received).

### USART status register C
|URSEL |UMSEL |UPM1 |UPM0 |USBS |UCSZ1 |UCSZ0 |UCPOL|
| ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- |
* ### URSEL(USART Register Select):This bit selects between accessing the UCSRC or the UBRRH Register, as both register shares the same address. The URSEL must be one when writing the UCSRC or else data will be written in the UBRRH register.
* ### UMSEL(USART Mode Select):  This bit selects between the Asynchronous and Synchronous mode of operation.
* ### UPM1:0(Parity mode):These bits enable and set the type of parity generation and check.
* ### USBS(USART Stop Bit Select):This bit selects the number of Stop Bits to be inserted by the Transmitter.The Receiver ignores this setting.
* ### UCSZ0:1(Character size):These bits combined with UCSZ2 bit in the UCSRB sets the number of data bits in a frame.
* ### UCPOL(Clock Polarity):This bit is used in synchronous mode only.Set to 0 for async.

### UBRR:USART Baud Rate Register
### UBRR=Fosc/(16xBaudrate) -1
```
#define USART_BAUDRATE 9600
#define UBRR_BAUD ((F_CPU/(BAUDRATE*16UL)) -1) //This value will be loaded in the UBRR register to set defined baud rate
```

### USART Initialisation 
```
void USART_init(USART_BAUDRATE)
{
  UCSR0B |=(1<<RXEN0)|(1<<TXEN0);  //Enable Transmission and Receiver
  UCSR0C |=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1); //Set character size to 8-bit
  UBRR0L=UBRR_BAUD;  //Load lower 8-bits of baud rate
  UBRR0H=(UBRR_BAUD>>8)  //Load upper 8-bits of baud rate
}
```

### Receiving Character
```
unsigned char USART_rx_char()
{
  while(UCSR0A & (1<<RXC0))  //Wait till data is received i.e when there is unread data in UDR
  return(UDR);  //Return the byte
}
```
### Transmitting Character
```
void USART_tx_char(char text)
{
  while(!(UCSR0A & (1<<UDRE0)))  //Wait till buffer is empty i.e-UDR is ready to transmit new data
  UDR=text; Load data to UDR for transmission
}
```
### Transmitting String
```
void USART_tx_string(char *str)
{
  unsigned int j=0;
  while(str[j]!=0)  //send string till null 
  {
    USART_tx_char(str[j]);
    j++;
  }
}
```
