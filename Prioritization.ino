
#if CONFIG_FREERTOS_UNICORE
  static const BaseType_t app_cpu = 0;
#else
  static const BaseType_t app_cpu = 1;
#endif

//define inbuild led pin
static const int LED = 2;
int LED_delay = 500;

// task handles
static TaskHandle_t task_1 = NULL;
static TaskHandle_t task_2 = NULL;

void startTask1(void *parameter){ //read value from serial monitor
  int inp;
  while(1){
    if(Serial.available()>0){
      inp = Serial.parseInt();
      Serial.println(inp);
      if(inp>0){
        LED_delay = inp;
      }
  }
 }
}
// Task to blink led based on global delay parameter
void startTask2(void *parameter){
  Serial.println("Running Task2");
  while(1){
    Serial.print("LED_delay val= ");
    Serial.println(LED_delay);
    digitalWrite(LED,HIGH);
    vTaskDelay(LED_delay/portTICK_PERIOD_MS); 
    digitalWrite(LED,LOW);
    vTaskDelay(LED_delay/portTICK_PERIOD_MS);
    }
  }


void setup() {
  // put your setup code here, to run once:
  Serial.begin(300);  // slow serial to observe the preemption
  pinMode(LED,OUTPUT);
  // Task to run forever
  xTaskCreatePinnedToCore(startTask1,"Read Serial",1024,NULL,1,&task_1,app_cpu);
  xTaskCreatePinnedToCore(startTask2,"Blink Led",1024,NULL,1,&task_2,app_cpu);
}

void loop() {
}
