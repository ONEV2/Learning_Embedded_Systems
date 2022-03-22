## Asynchronous vs Synchronous Serial Transmission
### Synchronisation allows both the transmitter and receiver to be expecting data transmission/reception at the same time.The sync can be maintained b/w trans and recv using 2 basic methods:
* ### Asynchronous Serial:- Framing bits are used at the start and end of a data byte.Framing bits alert the recv that data byte has arrived and also signals the completion of the data byte reception.Data rate is slow as compared to other system,but only 1 wire is required b/w trans and recv.
* ### Synchronous Serial:-Maintains sync by employing a common clock b/w the two devices.Data bits are send/recv on the edge of the clock.Data transfer rate is fast but requires two lines,data and clock b/w trans and recv.

## Baud Rate
### Data transmission rates are typically specified as a baud or bits per second rate,ex-9600 baud indicates a data transfer speed of 9600 bits/second.

## Full Duplex
### To transfer and recv data at the same time separate hardware is required.A single duplex system has a single hardware that must be switched from transmission to reception configuration,whereas a Full duplex system has a separate hardware for transmission and reception.

## Nonreturn to Zero coding format
### The Atmel Atmega328p uses a nonreturn to zero coding standard.In nonreturn to zero coding, a logic 1 is signaled by a logic high during the entire time slot allocated for a single bit,whereas a logic 0 is signaled by a logic low during the entire time slot allocated for a single bit.

## The RS-232 Communication Protocol
### To ensure data integrity over long distance(Logic level degrades over long distanc),RS-232 standard is used.With the RS-232 standard a logic 1 is represented with -12-VDC level whereas logic 0 is represented with +12-VDC level.Commonly available chips are used to convert 5 and 0 V to RS-232 compatible level.

## Parity
### To further enhance data integrity during transmission,parity techniques are used.Parity is an additional bit(bits) that may be transmitted with the data byte.The Atmega328p uses a single parity bit.With a single parity bit,a single-bit error may be detected.Parity can be even or odd.In even parity,the parity bit is set to 1 or 0,such that the no of 1's in the data byte including the parity bit is even(odd for odd parity).At the receiver,the number of bits within a data byte including the parity bit are counted to ensure that parity has not changed,indicating an error,duirng transmission.

## ASCII
### It is a standard 7-bit method of encoding alphanumeric data.ex- "G" in ASCII is 0x47.ASCII is a subset of Unicode(standardized 16-bit encoding format for the written languages of the world)

## Serial USART
### Serial USART provides full duplex communication b/w trans and recv.It is typically used for asynchronous communication.Framing start and stop bits are used at the beginning and end of each data byte in a transmission sequence.
### It can be set to various baud rates.The USART may also be set for data bit widths of 5 to 9 bits with 1 or 2 stop bits.

### USART data register
### UDR(read)
|RXB7|RXB6|RXB5|RXB4|RXB3|RXB2|RXB1|RXB0|
| ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- |
### UDR(write)

|TXB7 |TXB6 |TXB5 |TXB4 |TXB3 |TXB2 |TXB1| TXB0|
| ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- |
### USART status register A
|RXC |TXC |UDRE |FE |DOR |PE |U2X |MPCM|
| ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- |
### USART status register B
|RXCIE |TXCIE |UDRIE |RXEN |TXEN |UCSZ2 |RXB8 |TXB8|
| ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- |
### USART status register C
|URSEL=1 |UMSEL |UPM1 |UPM0 |USBS |UCSZ1 |UCSZ0 |UCPOL|
| ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- |

### USART has following basic parts:
* ### USART Clock generator:-Provides the clock source for the USART system and sets the baud rate for the USART.The baud rate is derrived from the overall clock source,The overall system clock is divided by USART baud rate registers UBBR[H:L] and several additional dividers to set the baud rate rate.Baud rate can be derrived from the following expression 
```
baud rate = (system clock frequency)/(2(UBRR+1))
```
* ### USART Transmitter:-Consists of a transmit shift register.The data to be transmitted are loaded into Transmit shift registers via the USART I/O data register(UDR).Start and stop framing bits along with parity bit are automatically calculated and appended to transmit shift register.Data are then shifted out of the Transmit shift register via the TxD pin a single bit at a time at the established baud rate.USART tranmitter is equipped with two status flags: UDRE(USART data register empty) and TXC(transmit complete).UDRE is set when transmit buffer is empty,indicating it is ready to receive new data.This bit should be written 0 when writing to UCSRA.UDRE bit is cleared by writing to UDR.The TxC flag is set to logic 1 when the entire frame in the transmit shift register has been shifted out and there is no new data currently present in transmit buffer

* ### USART receiver:-Similar to transmitter except for the direction of data flow.It is equipped with RxC flag,The RxC flag is set to logic 1 when unread data exist in the receiver buffer.

## USART basic working
![USART working flowchart]()

## Serial Peripheral Interface
### The Atmega328p also supports 2-way serial communication b/w trans and recv.In SPI a common clock is shared b/w trans and recv.It is fast but requires 1 extra wire for clock line.

## SPI Operation
### The SPI may be viewed as a synchronous 16-bit shift register with 8-bit half residing in the transmitter and the other 8-bit half residing in the receiver.The transmitter is designated the master because it provides the synchronizing clock source between the transmitter and the receiver  The receiver is designated as the slave. A slave is chosen for reception by taking its slave select (SS) line low. When the SS line is taken low, the slave’s shifting capability is enabled. SPI transmission is initiated by loading a data byte into the master configured SPI Data Register (SPDR). At that time, the SPI clock generator provides clock pulses to the master and also to the slave via the SCK pin. A single bit is shifted out of the master designated shift register on the Master Out Slave In (MOSI) microcontroller pin on every SCK pulse.The data are received at the MOSI pin of the slave designated device. At the same time, a single bit is shifted out of the Master In Slave Out (MISO) pin of the slave device and into the MISO pin of the master device. After eight master SCK clock pulses, a byte of data has been exchanged between the master and slave designated SPI devices. Completion of data transmission in the master and data reception in the slave is signaled by the SPI Interrupt Flag (SPIF) in both devices. The SPIF flag is located in the SPI Status Register (SPSR) of each device. At that time,another data byte may be transmitted.

## Registers:-
* ### SPI control register:-Contains on/off switch for SPI systems.
|SPIE|SPE|DORD|MSTR|CPOL|CPHA|SPR1|SPR0|
| ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- |

* ### SPI status register:-This contains the SPIF flag,The flag is set when the 8 bit data have been tranferred from master to slave.
|SPIF|WCOL|--- |--- |--- |--- |---|SPI2X|
| ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- |

* ### SPI data register:-
|MSB|||||||LSB|
| ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- |

## Two-Wire-Interface
### It alows us to connect a number of related devices using a two wire scheme.It allows a max of 128 devices connected together with each device having its own unique address and supports a maximum frequency of 400 kHz
