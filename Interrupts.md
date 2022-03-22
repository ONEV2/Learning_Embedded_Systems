## Interrupts
A microcontroller normally fetches an instruction, decode it and then executes it, To handle unexpected/high priority events, microcontrollers are equipped with interrupts.
These high priority events may be planned but there occurance may not be known. When interrupt occurs, CPU completes the task it is currently executing and then move to the interrupt. The tasks that handles these interrupts are stored in a function called ISR(Interrupt Service Routine). Each interrupt will have its own Interrupt Service Routine.

When an interrupt occurs, the microcontroller completes the current instruction, stores the
address of the next instruction on the stack, and starts executing instructions in the designated ISR
corresponding to the particular interrupt source. It also turns off the interrupt system to prevent
further interrupts while one is in progress. The execution of the ISR is performed by loading the
beginning address of the ISR specific for that interrupt into the program counter. The ISR will
then commence. Execution of the ISR continues until the return from interrupt instruction (reti)
is encountered. Program control then reverts back to the main program.

```
#pragma interrupt_handler timer_handler:4

void timer_handler(void){;}
```
Reserved word interrupt_handler is used to tell the compiler that timer_handler is an ISR and the number following it links the ISR to the corresponding vector address.

## External_Interrupt
INT0, INT1 and INT2 trigger an interrupt when an input is given to the pins associated to the external interrupts(Pin16,Pin17 and Pin3)

```
//Enabling a INT0 interrupt

#pragma interrupt_handler int0_handler:2

void int0_handler(void){; // Interrupt Tasks}

void init_interrupt(){
DDRD |= 0xFB; //set PD2 as input
PORTD &= ~0x04; //clear all the bits and disable pull up register
GICR |= (1<<INT0); // Enable interrupt 0 pin, General Interrupt Control Register
MCUCR |= (1<<ISC00) | (1<<ISC01); // MCU control register
}
```

If we want to call interrupts inside another interrupt,we can specify that either manually by calling sei() in the ISR itself or by using a special ISR_NOBLOCK argument to the ISR() definition.

Always remember that enabling interrupts is a two-step process; enable your specific interrupt vector, then enable the overall interrupt system with sei() .

## Pin change Interrupt
If we want to generate interrupts from pin other than INT0 or INT1, then we can use pin change interrupt.
If the interrupts are triggered by multiple pins, we need to test which pin caused the interrupt in the ISR itself

```
ISR(PCINT2_vect){
    if((PIND & (1<<PD2)) == 0){  //button at pin 2 is pressed
      // Do something
    }
    else if((PIND & (1<<PD4) == 0){ //button at pin 4 is pressed
      // Do something
    }
}

void init_pinchanage_Interrupt(void){
  PCICR |= (1<<PCIE2);  // set all pin D pins as interrupts
  PCMSK2 |= (1<<PD2) | (1<<PD4);  // enable pin 2 and 4 as interrupts
  sei();
}
```
