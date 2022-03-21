```
/*
 * SPI_AVR.c
 * MCU:Atmega328p
 * Created: 29-04-2021 01:30:19
 * Author : prakhar agrawal
 */
 
#ifndef F_CPU
#define F_CPU 16000000UL //clock speed with external crystal of 16 MHz
#endif

#define MOSI 3								/* Define SPI bus pins */
#define MISO 4
#define SCK 5
#define SS 2
#define SS_Enable PORTB &= ~(1<<SS)			/* Define Slave enable */
#define SS_Disable PORTB |= (1<<SS)			/* Define Slave disable */
```
### SPI Control Register
|SPIE|SPE|DORD|MSTR|CPOL|CPHA|SPR1|SPR0|
| ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- |
* ### SPIE(SPI Interrupt Enable bit)
  #### 1 = Enable SPI interrupt.
  #### 0 = Disable SPI interrupt.
* ### SPE(SPI Enable bit)
  #### 1 = Enable SPI.
  #### 0 = Disable SPI.
* ### DORD(Data Order Bit)
  #### 1 = LSB transmitted first.
  #### 0 = MSB transmitted first.
* ### MSTR(Master/Slave Select bit)
  #### 1 = Master mode.
  #### 0 = Slave Mode.
* ### CPOL(Clock Polarity Select bit)
  #### 1 = Clock start from logical one.
  #### 0 = Clock start from logical zero.
* ### CPHA(Clock Phase Select bit)
  #### 1 = Data sample on trailing clock edge.
  #### 0 = Data sample on the leading clock edge.
* ### SPR1:SPR0(SPI Clock Rate Select bit)

### SPI Status Register
|SPIF|WCOL||||||SPI2X|
| ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- |
* ### SPIF(SPI Interrupt Flag bit):This flag is set when the serial transfer is complete
* ### WCOL(Write Collision Flag Bit):This bit gets set when SPI data register writes occur during previous data transfer
* ### SPI2X(Double SPI Speed bit):When set,SCK freq gets doubled

### SPI Data Register
#### It is used to transfer data b/w register file and SPI shift register.

### SPI Initialisation
#### Master
```
void SPI_init_master()
{
  DDRB |= (1<<MOSI)|(1<<SS)|(1<<SCK); //SCk,MOSI and SS pins are output pins
  DDRB &= ~(1<<MISO); //MISO pin is input pin 
  PORTB |= (1<<SS); //Make SS pin high
  SPCR |= (1<<SPE)|(1<<MSTR)|(1<<SPR1); //Enable SPI in master mode with Fosc=64
  SPSR &= ~(1<<SPI2X);  //Disable Speed doubler
}
```
#### Slave
```
void SPI_init_slave()
{
  DDRB &= ~((1<<MOSI)|(1<<SCK)|(1<<SS));  //SCK,MOSI and SS pins are input pins
  DDRB |= (1<<MISO);  //MISO pin is an output pin
  SPCR |= (1<<SPE); //Enable SPI in slave mode
}
```
### SPI Write
```
void SPI_write(char data)
{
  SPDR=data;  //Write data to SPI data register
  while(!(SPSR & (1<<SPIF));  //Wait till transmission is complete
}
```
### SPI Read 
#### Master
```
char SPI_read_master()
{
  SPDR=0xFF;
   while(!(SPSR & (1<<SPIF)); //Wait till reception is complete
   return(SPDR);  //Returns received data
}
```
#### Slave
```
char SPI_read_slave()
{
  while(!(SPSR & (1<<SPIF)); //Wait till reception is complete
  return(SPDR); //Returns received data
}
```
  
