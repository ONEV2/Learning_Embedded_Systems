#include <avr/io.h>
#include <util/delay.h>

char val;
void SPI_init(){
  DDRB &= ~(1<<MOSI) | (1<<SS) | (1<<SCK);  //Make mosi,ss and sck pin as input
  DDRB |= (1<<MISO);  //Make MISO as output
  SPCR |= (1<<SPE); //Enable SPI in slave mode
  }

char SPI_receive(){
  while(!(SPSR & (1<<SPIF))); //Wait till reception is complete
  return SPDR;  //return received data
  }

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("SPI_slave");
}

void loop() {
  // put your main code here, to run repeatedly:
  SPI_init();
  val = SPI_receive();
  Serial.println(val);

}
