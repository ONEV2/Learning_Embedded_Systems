## Bus Structure in 8085

<p align="center">
  <img src="https://scanftree.com/microprocessor/8085-bus-structure.JPG">
</p>

### Three buses in 8085 are-
1. Address bus
2. Data bus
3. Control bus

### Address bus:-
8085 has a 16 bit address bus, The bus over which the CPU send's address of a memory location is known as address bus. Address buses are unidirectional i.e- bit flow occurs in only one direction. No of address lines required to move lets say 1024 mb of memory=> 2^x = 1024 => x=10. Hence 10 address lines are required to access 1024mb of memory.

### Data bus:-
8085 has 8 bit data bus and is bi-directional. Since they are bi-directional they are used to connect I/O ports to CPU.8085 has 8 parallel lines of data bus. So it can access upto 2^8 = 256 data bus lines.

### Control bus:-
The control bus is used for sending control signals to the memory and I/O devices.The CPU sends control signal on the control bus to enable the outputs of addressed memory devices or I/O port devices.
Some of the control bus signals are as follows:
1. Memory read
2. Memory write
3. I/O read
4. I/O write
