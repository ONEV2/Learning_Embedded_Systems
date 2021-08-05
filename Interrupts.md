## Interrupts in 8085
Interrupt is a mechanism by which an I/O or an instruction can suspend the normal execution of the processor and get itself executed first. In the microprocessor based system the interrupts are used for data transfer between the peripheral devices and the microprocessor.

### ISR(Interrupt Service Routine)
A program or routine that when executed executes the interrupting source first by putting on hold the current task of the CPU.

### Maskable/Non-Maskable Interrupt
An interrupt that can be disabled by writing some instruction is known as Maskable Interrupt otherwise it is called Non-Maskable Interrupt.

### Execution of Interrupts
When there is an interrupt request to a microprocessor then after accepting the interrupt, Processor send the INTA (active low) signal to the peripheral. The vectored address of a particular interrupt is stored in the program counter. The processor executes an interrupt service routine (ISR) addressed in program counter.
There are two types of interrupts used in 8085 Microprocessor:
1. Hardware Interrupts
2. Software Interrupts

### Software Interrupts
A software interrupts is a set of  instructions that can be inserted into the desired location in the program. There are eight software interrupts in 8085. From RST0 to RST7.
1. RST0
2. RST1
3. RST2
4. RST3
5. RST4
6. RST5
7. RST6
8. RST7
They allow the processor to transfer program control from the main program to the subroutine program. After completing the subroutine program, the program control returns back to the main program.
```
Vector address = Interrupt Number * 8
ex- 
RST1:- vector address-> 1*8 = 8 = 08H
RST2:- vector address-> 2*8 = 16 = 10H
```
### Hardware Interrupts
There are 6 interrupt pins in the processor for the sake of hardware interrupts, they are-
1. TRAP
* It is a non maskable edge and level triggered interrupt.TRAP has the highest priority and vectores interrupt. Edge and level triggered means that the TRAP must go high and remain high until it is acknowledged. In case of sudden power failure, it executes a ISR and send the data from main memory to backup memory.As we know that TRAP can not be masked but it can be delayed using HOLD signal. This interrupt transfers the microprocessor's control to location 0024H.
3. RST7.5
* It has the second highest priority. It is maskable and edge sensitive triggered interrupt. The vector address of this interrupt is 003CH. Edge sensitive means input goes high and no need to maintain high state until it is recognized.
4. RST6.5
* It is level triggered and maskable interrupt. When RST6.5 pin is at logic 1, INTE flip-flop is set. RST 6.5 has third highest priority.
5. RST5.5
* It is level triggered and maskable interrupt. RST5.5  has fourth highest priority.
7. INTR
* It is level triggered and maskable interrupt.The following sequence of events occurs when INTR signal goes high:
- The 8085 checks the status of INTR signal during execution of each instruction.
- If INTR signal is high, then 8085 complete its current instruction and sends active low interrupt acknowledge signal, if the interrupt is enabled.
- On receiving the instruction, the 8085 save the address of next instruction on stack and execute received instruction.
