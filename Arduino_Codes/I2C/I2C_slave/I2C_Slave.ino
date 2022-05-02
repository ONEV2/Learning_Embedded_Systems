#include <avr/io.h>
#include <util/delay.h>

uint8_t arr[53];
#define Slave_addr 0x20

int i=0;
int val;
void setup(){
Serial.begin(115200);
Serial.println("Slave");
}
void loop(){
  I2C_init(Slave_addr);
  I2C_Listen();
  Serial.println(val);
  Serial.println("Slave initiated successfully");
  do{
  val = I2C_Receive();
  Serial.println(val,HEX);
  }
  while(val != -1);
  Serial.println("Transmission Complete");
  }
