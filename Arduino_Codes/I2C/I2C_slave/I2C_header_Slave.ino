#include <avr/io.h>

#ifndef I2C_HEADER_SLAVE_H
#define I2C_HEADER_SLAVE_H

void I2C_init(uint8_t slave_addr){
  TWAR = slave_addr; //Assign address in TWI address register
  TWCR |= (1<<TWEN) | (1<<TWEA) | (1<<TWINT);  //Enable TWI,Enable ACK generation,Clear interrupt flag
  }

uint8_t I2C_Receive(){
  uint8_t Status;
  TWCR |= (1<<TWEN) | (1<<TWINT) | (1<<TWEA); //Enable TWI,clear interrupt flag,Enable ACK gen
  while(!(TWCR & (1<<TWINT)));  //Wait untill transmission/Reception is complete
  Status = TWSR & 0xF8;
  if(Status == 0x80 || Status == 0x90)  //Check weather data received and ACK returned
  return TWDR;  //If yes,then return received data
  if(Status == 0x88 || Status == 0x98) //Check weather data received and NACK returned
  return TWDR;  //If yes,then return received data
  if(Status == 0xA0){  //Check weather start stop is received
    TWCR |= (1<<TWINT); //Clear interrupt flag
    return -1;  //If yes,return -1
  return TWDR;
  }
}

int8_t I2C_Listen(){
  while(1){
  uint8_t Status = TWSR & 0xF8;
    if(Status == 0x60 || Status == 0x68)  //Check weather own SLA+W received and ACK returned
    {
      Serial.println("Own SLA+W received,returning 0..");
      return 0;
      }
    else
      continue;
    }
  }
#endif 
