#include <avr/io.h>
#include <util/delay.h>

#define MOSI 1
#define SCK 2
#define SS 3

String crap_upper_8 = "2352gj2";
String crap_lower_8 = "rglsdnjs";

String flag_upper_8 = "Flag{You";
String flag_lower_8 = "_got_it}";

void SPI_init(void){
  DDRB |= (1<<MOSI) | (1<<SCK) | (1<<SS);
  DDRB &= ~(1<<MISO); //set MISO pin as input pin
  PORTB |= (1<<SS); //Make SS pin high,in master mode
  SPCR |= (1<<SPE) | (1<<MSTR) | (1<<SPR0); //Enable SPI in master mode with SCK = F_cpu/16
  SPSR &= ~(1<<SPI2X);  //disable speed doubler
  }

void SPI_Write(char data){
  char flush_buffer;
  SPDR = data;
  while(!(SPSR & (1<<SPIF))); //wait till transmission is complete
  Serial.println(data);
  flush_buffer = SPDR;  //clear the Interrupt flag and empty the data register
  }

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("SPI master");
}

void send_anything(String data){
  SPI_init();
  for(int i=0;i<sizeof(data);i++){
     SPI_Write(data[i]);
    _delay_ms(5);
    }
  }
void loop() {
  // put your main code here, to run repeatedly:
  send_anything(crap_upper_8);
  send_anything(crap_lower_8);
  send_anything(flag_upper_8);
  send_anything(flag_lower_8);
}
