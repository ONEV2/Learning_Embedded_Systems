// Using only 1 core
#if CONFIG_FREERTOS_UNICORE
static const BaseType_t app_cpu = 0;
#else
static const BaseType_t app_cpu = 1;
#endif

// pin
static const int pin = 2;

// task:blink an led
void toggleLED(void *parameter){
  while(1){
    digitalWrite(pin,HIGH);
    /*
     //This delay is used in RTOS and does not stop other tasks, it tells the controller
     //to do other work and once the delay time is out, come back to it again
     //by default portTICK_PERIOD_MS is set to 1 ms
    */
    vTaskDelay(1000/portTICK_PERIOD_MS);
    digitalWrite(pin,LOW);
    vTaskDelay(1000/portTICK_PERIOD_MS);
    }
  }

void fastLED(void *parameter){
  while(1){
  digitalWrite(pin,LOW);
  vTaskDelay(100/portTICK_PERIOD_MS);
  digitalWrite(pin,HIGH);
  vTaskDelay(100/portTICK_PERIOD_MS);
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(pin,OUTPUT);
  
  //task to run forever
  xTaskCreatePinnedToCore(  //Use xTaskCreate() in vanilla FreeRTOS
             toggleLED,     //function to be called
             "Toggle LED",  //Name of the task
             1024,          //Stack size is in bytes in ESP32 and in words in RTOS
             NULL,          //Parameter to pass to function
             1,             // Task priority
             NULL,          //Task handle
             app_cpu);      //Run on one core for learning purpose(ESP32 only)  

  xTaskCreatePinnedToCore(
             fastLED,
             "blink led fast",
             1024,
             NULL,
             1,
             NULL,
             app_cpu);
}
void loop() {
  // put your main code here, to run repeatedly:

}
