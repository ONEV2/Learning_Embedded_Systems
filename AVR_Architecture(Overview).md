## Architecture
### Atmega328p architecture is register-based,i.e-both operands of an operation are stored in registers place side by side with the central processing unit(CPU).This means that before an operation is performed,all the necessary data is loaded to CPU and the result is stored in a register.

### Coupled with the register-based architecture is an instruction set based on the RISC concept.A RISC processor is equipped with a number of very simple and efficient basic operations(Complex instructions can be build using these basic operations).There are 131 RISC-type instructions and most of them can be executed in a single clock cycle.

### Atmega328p has 32 general purpose 8-bit registers.Also,the processor is designed following the Harvard architecture format(dedicated memories and buses for program and data information.) 

### *The register based Harvard Architecture* coupled with  *The RISC based instruction set* allows for fast and efficient program execution.(Atemga328p can execute upto 16 million instructions per second)

## Nonvolatile and Data memories
### Atmega328p is equipped with 3 main memory secton:
* ### Flash EEPROM:- It is used to store programs.Flash EEPROMs are non-volatile,meaming memory contents are retained when microcontroller power is lost.Atmega328p is equipped with 32k bytes of onboard reprogramable flash memory.The flash EEPROM is in-system programmable,i.e-microcontroller can be programmed while resident within a circuit.

* ### Byte-addressable EEPROM:-It is a non-voltatile memory used to permanently store and recall variables during program execution.It is useful especially for logging system malfunctions and fault data during program execution.Atmega328p is equipped with 1024 bytes of EEPROM.

* ### SRAM:-It is a voltatile memory,small portion of the SRAM is set aside for the general-purpose registers used by the CPU and also for the I/O and peripheral subsystems abord the microcontroller.

## Programmable lock bits
### To provide for memory security from tampering,Atmega328p is equipped with lock bits,The lock bits may be configured for the following options:
* ### No memory lock feature enabled.
* ### No further programming or verification of memory is allowed using parallel or serial techniques.

## Port Systems
### Atmega328p is equipped with three 8-bit general purpose,digital I/O ports.Each port has 3 register associated with it:
* ### DDRx:-used to set a specific port pin to either output (1) or input (0).
* ### PORTx:-used to write output data to the port
* ### PINx:-used to read input data from the port

## Time base
### Microcontroller responds to program steps in a sequential manner as dictated by a user-written program.It sequences through a predictable fetch--decode--execute sequence.The speed at which a microcontroller sequences through these instructions is controlled by a precise time base called the clock.The clock source is routed throught the controller to provide time base for all peripheral subsystems.

### Internal time base is selected using programmable fuse bits.To provide for a wider range of frequency selections,an external source may be used.(Ceramic or Crystal oscillator)

## Pulse Width Modulation Channels
### A PWM signal has fix frequency and variable duty cycle(%age of time a repetative signal is logic high).
### The Atmega328p is equipped with 6 PWM channels.
### PWM signal are used in wide variety of applications,including controller the pos of servo motor,speed of DC motor etc.

## Serial Communication
### Atmega328p is equipped with a host of different serial communication subsystems,including:-
* ### USART:-Used for 2-way communication,typically used for asynchronous communication,i.e-there is not a common clock between transmitter and receiver.Syncronisation is maintained by sending start and stop bits along with data byte.
### The Atmega328p is equipped with a hardware-generated parity bit(even or odd) and parity check hardware at the receiver.A single parity bit allows for the detection of a single bit error within a byte of data.

* ### SPI:-Used for 2-way communication,transmitter and receiver shares a common clock source.SPI may be viewed as a synchronous 16-bit shift register with an 8-bit half residing in the transmitter and the other half residing in the receiver.

* ### I2C:-Used to connect a network of devices(max 128),Each device has its own unique address and may both transmit and receive at frequencies up to 400kHz.

## Analog-To-Digital Converter
### The Atmega328p is equipped with an eight-channel ADC subsystem.
### ADC converts an analog signal from the outside world into a binary representation suitable for use by the microcontroller.

## Stack and Stack pointers
* ### Stack:- Data allocated in internal SRAM for storing temporary data,local variables and return addresses after interrupts and subroutine calls.When interrupts and subroutine calls are executed,the return address is stored on the stack.Stack size is limited by total SRAM size and the usage of SRAM.

* ### Stack pointer:- 16 bit registers composed of two 8 bit registers SPL and SPH.Points to the top of the stack,which is in the data SRAM stack area where the subroutine and interrupt stacks are located.

## Interrupts
### The normal execution of a program step follows a designated sequence of instructions.However,sometimes, this normal sequence of events must be interrupted to respond to high-priority faults and status both inside and outside the microcontroller.When these higher-priority events occur, the microcontroller must temporarily suspend normal operation and execute event specific actions called an interrupt service routine. Once the higher priority event has been serviced, the microcontroller returns and continues processing the normal program.
