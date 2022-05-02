/*
 * blink led
 * Created by - Prakhar Agrawal
 * Date - 25-04-22
 * Time - 14:38
 */

void GPIO_init(void){
  DDRB = 0xFF;  //set PORT B pins as output pins
  }

void GPIO_blink(void){
  PORTB = 0xFF;
  _delay_ms(500);
  PORTB = 0x00;
  _delay_ms(500);
  }
void setup() {
  // put your setup code here, to run once:
   GPIO_init();
}

void loop() {
  // put your main code here, to run repeatedly:
  GPIO_blink();

}
