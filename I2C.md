```
/*
 * I2C_AVR.c
 * MCU:Atmega328p
 * Created: 01-05-2021 12:35:19
 * Author : prakhar agrawal
 */
 
#ifndef F_CPU
#define F_CPU 16000000UL //clock speed with external crystal of 16 MHz
#endif
```

## TWBR(TWI Bit Rate Register):It is used in generating SCL frequency while operating in the master mode
|TWBR7|TWBR6|TWBR5|TWBR4|TWBR3|TWBR2|TWBR1|TWBR0|
| ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- |


## TWCR(TWI Control Register):It is used to control events of all I2C communications.

|TWINT|TWEA|TWSTA|TWSTO|TWWC|TWEN|-|TWIE|
| ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- |
* ### TWINT(TWI Interrupt):This bit gets set when TWI completes its current event(like start,stop,transmit,receive etc..).TWI Interrupt flag must be cleared by writing 1 to it as it is not automatically cleared by hardware.
* ### TWEA(TWI Enable Acknowledgment bit):It is set in the receiver mode to generate acknowledgment and cleared in transmit mode.
* ### TWSTA(TWI Start Condition bit):The master device sets this bit to generate start condition.
* ### TWSTO(TWI Stop Condition bit):The master device sets this bit to generate stop condition.
* ### TWWC(TWI Write Collision):This bit gets set when writing to the TWDR and TWINT is low.
* ### TWEN(TWI Enable bit):This bit is set to enable TWI interface in the device and take control over the I/O pins.
* ### TWIE(TWI Interrupt Enable):This bit is used to enable TWI to interrupt routine.

## TWSR(TWI Status Register)
|TWS7|TWS6|TWS5|TWS4|TWS3|-|TWPS1|TWPS0|
| ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- |
* ### TWS[7:3]\(TWI Status bits):These bits show the status of TWI control and bus.
* ### TWPS[1:0]\(TWI Pre-scaler bits)

## TWDR(TWI Data Register):TWDR contains data to be transmitted or received.
### It’s not writable while TWI is in process of shifting a byte.

## TWAR(TWI Address Register):It contains the address of the TWI unit in slave mode.
|TWA6|TWA5|TWA4|TWA3|TWA2|TWA1|TWA0|TWGCE|
| ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- |
* ### TWA[6:0]\(TWI Address bits):These bits contain TWI 7-bit address with which it can be called by other masters in slave mode.
* ### TWGCE(TWI General Call Enable bit):TWI general call enable bit enables recognition of general calls over the TWI bus.

## I2C Initialisation 
1. ### Set baud rate for data transfer in TWBR

  #### TWBR can be calculated using:- 
```
SCL_clock =(CPU_clock_freq)/(16+2*(TWBR)*4^TWPS)
CPU_clock_freq=16 MHz,SCL_freq=10 kHz and let Prescaler be 1(TWPS[1:0]=0)
So TWBR=196 in decimal or C4 in hex
```
2. ### Set the TWEN bit in TWCR for enabling TWI communication
  #### TWCR will have following bits enabled:- 
|Name|TWINT|TWEA|TWSTA|TWSTO|TWWC|TWEN|-|TWIE|
| ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- |
|Value||||||1|||

3. ### Set prescaler in TWSR
  #### TWSR will have following bits enabled:-
|Name|TWS7|TWS6|TWS5|TWS4|TWS3|-|TWPS1|TWPS0|
| ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- |
|Value|||||||0|0|

## I2C Start Condition
1. ### Clear TWINT by setting it to 1
2. ### Set TWSTA bit as 1
3. ### Set TWEN bit
|Name|TWINT|TWEA|TWSTA|TWSTO|TWWC|TWEN|-|TWIE|
| ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- |
|Value|1||1|||1|||
4. ### Check for TWINT bit set in TWCR 
```
while(!(TWCR & (1<<TWINT)));
```
## I2C Stop Condition
1. ### Clear TWINT bit by setting it to 1
2. ### Set TWEN bit 
3. ### Set TWSTO bit as 1
|Name|TWINT|TWEA|TWSTA|TWSTO|TWWC|TWEN|-|TWIE|
| ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- |
|Value|1|||1||1|||

## I2C Write Condition
1. ### Move data to be transmitted to slave in TWDR
2. ### Clear TWINT bit by setting it to 1 
|Name|TWINT|TWEA|TWSTA|TWSTO|TWWC|TWEN|-|TWIE|
| ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- |
|Value|1|||||1|||
3. ### Check for TWINT bit set in TWCR 
```
while(!(TWCR) & (1<<TWINT)));
```

## I2C Read Condition
1. ### Clear TWINT bit by setting it to 1.
|Name|TWINT|TWEA|TWSTA|TWSTO|TWWC|TWEN|-|TWIE|
| ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- |
|Value|1|||||1|||
2. ### Check for TWINT bit set in TWCR
3. ### Return TWDR using Return function
```
while(!(TWCR) & (1<<TWINT)));
Return value in TWDR;
```

## I2C Master Device
```
void I2C_init()
{
  TWCR = (1<<TWEN)  //Enables TWI Interface
}

int I2C_start(char write_address)
{
  unsigned int status;  //Create a status variable
  //Sending and Checking for start condition
  TWCR=(1<<TWEN)|(TWSTA)|(1<<TWINT);  //Enable TWI,generate start condition and clear interrupt flag
  while(!(TWCR & (1<<TWINT))); //Wait till TWI finish its current job
  status=TWSR & 0xf8; //0xf8(11111000) Set prescalar bits as 0
  if(status != 0x08) //Check weather start condition succesfully or not
  return 0; //if not return 0 to indicate start condition failed
  //Sending SLA+W and checking for ack or nack received or not
  TWDR=write_address; //if yes then write SLA+W in TWI data register
  TWCR=(1<<TWEN)|(TWINT); //Enable TWI and clear interrupt flag
  while(!(TWCR & (1<<TWINT)));  //Wait till TWI finishes it current job
  status = TWSR & 0xF8; //Read TWI status register with masking lower 3 bits
  if(status==0x18) //Check weather SLA+W transmitted and ack received or not
  return 1; //if yes then return 1
  else if(status==0x20)  //Check weather SLA+W transmitted and nack received or not
  return 2; //if yes then return 2
  else
  return 3; //Else return 3 to indicate that SLA+W failed
}

int I2C_repeat_start(char read_address)
{
  unsigned int status;
  //Sending and Checking for repeated start condition
  TWCR=(1<<TWEN)|(1<<TWSTA)|(1<<TWINT); ///Enable TWI,generate start condition and clear interrupt flag
  status=TWWR & 0xF8; //Read TWSR with masking lower 3 bits
  if(status!=0x10); //Check weather repeated start condition transmitted or not
  return 0; //if no return 0
  //Sending SLA+R and checking for ack or nack received or not
  TWDR=read_address;  //if yes then write SLA+R in TWDI
  TWCR=(1<<TWEN)|(1<<TWINT);  //Enable TWI and clear interrupt flag
  while(!(TWCR & (1<<TWINT)));  ///Wait till TWI finishes it current job
  status = TWSR & 0xF8; //Read TWI status register with masking lower 3 bits
  if(status==0x40)  //Check weather SLA+R transmitted and ack received or not
  return 1; //if yes return 1
  else if(status==0x20) //Check weather SLA+R transmitted and nack received or not
  return 2; //if yes return 2
  else
  return 3; //Else return 3 to indicate that SLA+R failed
}

void I2C_stop()
{
  TWCR=(1<<TWEN)|(1<<TWSTO)|(1<<TWINT); //Enable TWI, generate stop condition and clear interrupt flag
  while(TWCR & (1<<TWSTO));  //Wait until stop condition execution 
}

void I2C_start_wait(char write_address)
{
  unsigned int status;
  while(1)
  {
     TWCR=(1<<TWEN)|(TWSTA)|(1<<TWINT);
      while(!(TWCR & (1<<TWINT)));
      status = TWSR & 0xF8;
      if(status!=0x08)
      continue;
      TWDR=write_address;
      TWCR=(1<<TWEN)|(1<<TWINT);
      while(!(TWCR & (1<<TWINT)));
      status=TWSR & 0xF8;
      if(status!=0x18)
      {
        I2C_stop();
        continue;
      }
      break;
  }
}

int I2C_write(char data)
{
  int status;
  TWDR=data;  Load data in TWDR register
  TWCR=(1<<TWEN)|(1<<TWINT);  //Enable TWI and clear interrupt flag
  while(!(TWCR & (1<<TWINT)));  //Wait untill TWI finishes its current job;
  status=TWSR & 0xF8; //Read TWSR with masking lower 3 bits
  if(status==0x28)  //Check weather data transmitted and ack received
  return 0; //if yes return 0
  else if(status==0x30)  //Check weather data transmitted and nack received
  return 1; //if yes return 1;
  else
  return 2;
}

char I2C_read_ack()
{
  TWCR=(1<<TWEN)|(1<<TWINT)|(1<<TWEA);  //Enable TWI,clear interrupt flag and enable generation of ack
  while(!(TWCR & (1<<TWINT)));  //Wait until TWI finishes its current job
  return TWDR; //Return received data
}

char I2C_read_nack()
{
  TWCR=(1<<TWEN)|(1<<TWINT);  //Enable TWI,clear interrupt flag
  while(!(TWCR & (1<<TWINT)));  //Wait until TWI finishes its current job
  return TWDR; //Return received data
}

```
