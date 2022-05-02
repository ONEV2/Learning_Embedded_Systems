Real time applications are the ones that have fixed time constraints.

They may not be very fast executing applications,but they are time deterministic i.e their response time to the events are almost constant. Ex- Airbag systems, Guided weapons etc.

### RTOS
It a OS, specifically designed to run applications with very precise timing.

In RTOS,threads execute in the order of their priority. i.e - If a high priority thread becomes ready to run, it will take over the CPU from any low-priority executing thread.



### GPOS
GPOS or general purpose operating system is programmed to handle scheduling to achieve high throughput(total no of processes/tasks completed per unit time)

### Task
A task is a piece of code which is scheduable.

#### Creating a task:- 
```
BaseType_t xTaskCreate( 
//name of task function
TaskFunction_t pvTaskCode,
//descriptive name for the task
const char* const pcName,
//stack size for the task
unsigned short usStackDepth,
//used to pass the pointer of the data to the task function
void *pvParameters,
//Set priority of the task
UBaseType_t uxPriority,
//Get the handle(pointer to task creation block in memory) to the task
TaskHandle_t *pxCreatedTask
);
```
#### Task Implementation
```
void vATaskFunction(void *pvParamenters)
{
    for(;;){
        // -- Task application code here -- 
    }

    vTaskDelete(NULL);
}
```
When we create a task, memory is allocated in TCB(task control block) and  also the stack size is set on the heap.