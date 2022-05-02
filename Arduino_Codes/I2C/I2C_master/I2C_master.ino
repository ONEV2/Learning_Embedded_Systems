#include <avr/io.h>
#include <util/delay.h>

#define Slave_Write_Addr 0x20

String Crap_upper_8 = "sdg458";
String Crap_middle_8 = "3463tu";
String Crap_lower_8 = "wptjwp";

String flag_upper_8 = "flag{y";
String flag_middle_8 = "ou_got";
String flag_last_8 = "_it}-+";

int flag=0;
void setup(){
  Serial.begin(115200);
  Serial.println("Master");
  }
void send_anything(String data){
I2C_init();
  Serial.println("Write slave adrress");
  I2C_Start(Slave_Write_Addr);
  _delay_ms(5);
  for(int i=0;i<sizeof(data);i++){
    I2C_Write(data[i]);
    Serial.println("Sending data...");
    Serial.println(data[i]);
    _delay_ms(5);
  } 
  I2C_Stop(); //Stop I2C
  Serial.println("Transmission Complete");
} 
void loop(){

  send_anything(Crap_upper_8);
  send_anything(Crap_middle_8);
  send_anything(Crap_lower_8);
  
  if(flag==7){
  send_anything(flag_upper_8);
  send_anything(flag_middle_8);
  send_anything(flag_last_8);
  }
  flag++;
  }
