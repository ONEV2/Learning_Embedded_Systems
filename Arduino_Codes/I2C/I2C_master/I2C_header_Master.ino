/*
 * I2C Master header file
 * Master Transmission mode
 * Created by - Prakhar Agrawal, Ranit Pradhan
 * Time - 00:21 AM
 * Date - 24-04-22
 */

#include <avr/io.h>

#ifndef I2C_HEADER_MASTER_H
#define I2C_HEADER_MASTER_H

void I2C_init(void){
 //set SCL
   TWSR |= 0x00; //prescaler is not being used
   TWBR |= 0x0C;  //set the SCL to 400KHz (SCL = CPU_freq/(16+(2*TWBR)*Prescaler)) 
   //Enable I2C
   TWCR |= (1<<TWEN);
  }

void I2C_Start(uint8_t write_addr){
 uint8_t Status;
 while(1){
     TWCR = (1<<TWEN) | (1<<TWSTA) | (1<<TWINT);
     while(!(TWCR & (1<<TWINT)));
     Status = TWSR & 0xF8;
     if(Status != 0x08){
         continue;
     }
     TWDR = write_addr;
     TWCR = (1<<TWEN) | (1<<TWINT);
     while(!(TWCR & (1<<TWINT)));
     Status = TWSR & 0xF8;
     if(Status!= 0x18){
         I2C_Stop();
         continue;
     }
     break;
 }
}

void I2C_Stop(void){
  // Function to generate stop signals
  // TWINT is set to 1 to clear the interrupt flag
  // TWSTO is set to 1(in master mode) to generate STOP condition
  TWCR |= (1<<TWINT) | (1<<TWSTO) | (1<<TWEN); 
  while(TWCR & (1<<TWSTO)); //wait until stop condition is executed
  }

void I2C_Write(uint8_t data){
  TWDR = data;  //write data to data register
  TWCR |= (1<<TWINT) | (1<<TWEN); //clear the interrupt flag and enable TWI
  while(TWCR & (1<<TWINT)==0){
    Serial.println("Waiting for Transmission to Complete");
    }; //wait for the transmission to be completed 
  }
  
void I2C_Start_Wait(char write_address)            /* I2C start wait function */
{
  uint8_t status;                     /* Declare variable */
  while (1)
  {
    TWCR = (1<<TWSTA)|(1<<TWEN)|(1<<TWINT);       /* Enable TWI, generate start condition and clear interrupt flag */
    while (!(TWCR & (1<<TWINT)));           /* Wait until TWI finish its current job (start condition) */
    status = TWSR & 0xF8;               /* Read TWI status register with masking lower three bits */
    if (status != 0x08){                 /* Check weather start condition transmitted successfully or not? */
    Serial.println("Start condition transmission failed");
    continue; 
    }/* If no then continue with start loop again */
    TWDR = write_address;               /* If yes then write SLA+W in TWI data register */
    TWCR = (1<<TWEN)|(1<<TWINT);            /* Enable TWI and clear interrupt flag */
    while (!(TWCR & (1<<TWINT)));           /* Wait until TWI finish its current job (Write operation) */
    status = TWSR & 0xF8;               /* Read TWI status register with masking lower three bits */
    if (status != 0x18 )                /* Check weather SLA+W transmitted & ack received or not? */
    {
      I2C_Stop();                   /* If not then generate stop condition */
      continue;                   /* continue with start loop again */
    }
    break;                        /* If yes then break loop */
  }
}

#endif
