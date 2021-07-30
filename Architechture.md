## Architechture of 8085
<p align=center>
  <img src="https://scanftree.com/microprocessor/Architechture-of-8085-block.PNG" widht=300, height=300>
</p>

### Accumulator
It is an 8-bit register which is used while performing ALU operations.In simple words it stores the output of any operation while also working as an i/o register.

### Temporary Register
It holds the data on which accumultor is performing an operation.It can also be called as operand register as it provides operand to ALU.

### Registers
These are general purpose registers. 8085 has 6 general purpose registers each of 8-bits namely- B,C,D,E,H,L,They are generally used during the execution of the instructions.They can also carry 16 bits data by being used as pairs- BC,DE and HL.

### ALU
ALU performs the arithmetic and logical operations.

### Flag Registers
They are also known as status registers because of the fact that these registers change their status using flip-flops according to the result stored in accumulator.There are 5 flip-flops in the flag register- 

|D7 |D6 |D5 |D4 |D3 |D2 |D1 |D0 |
|-|-|-|-|-|-|-|-|
|S(Sign) |Z(zero) | |AC(Auxiliary carry) | |P(Parity) | |CY(Carry) |

1. Sign flag- It is used to give information about the sign of number,i.e- if flag is set to 1,it indicates that number is negative and vice-versa.
2. Zero flag- This flag is set when the result stored in the accumulator is zero.
3. Auxiliary carry- If any carry goes from D3 to D4 in the output then it is set.
4. Parity- It is set if the number of 1's is even in the output stored in the accumulator.
5. Carry flag- It is set if the result stored in the accumulator generates a carry.

### Instruction registers
It is an 8-bit register which stores the instructions fetched from memory.

### Instruction decoder
It is used to indentify instructions.It works by taking infromation from IR and then decodes the instruction to be performed.

### Program Counter
It is a 16 bit register and used as a memory pointer. It stores the memory address of the next instruction to be executed.At the beginning PC is set to 0x0H.

### Stack Pointer
It is also a 16 bit register used as memory pointer.It points to the memory location called stack.Stack is generally a reserved portion of memory where information can be stored or retrived.

### Timing and control unit
It provides timing and control signal to the microprocessor to perform various operations.There are 3 control signal-
1. ALE-Airthmetic Latch Enable, It provides control signal to synchronize the components of microprocessor.
2. RD- This is active low used for reading operation.
3. WR-This is active low used for writing operation.

### Serial Input/Output Control
It is used for serial data communication

### Interrupt unit
There are 6 interrupt pins in this unit.Generally external hardware is connected to these pins such that these pins provide interrupts caused by external devices to microprocessor and in return processor sends back an acknowledgement bit.
