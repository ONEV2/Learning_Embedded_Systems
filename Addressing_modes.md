## Addressing modes
1. Immediate
2. Register
3. Direct 
4. Indirect
5. Implied/Implicit

### Immediate Addressing mode
In this mode data is transferred directly to the register.
```
MVI A,0x05  ;(0x05 is copied to register A)
```

### Register Addressing mode
In this mode data is copied from one register to another.
```
MOV B,A ;(Contents of A is copied to register B)
```

### Direct Addressing mode
In this mode data is directly copied from the given address to the register.
```
LDA 3000H ;(The contents at the location 3000H is copied to the accumulator A)
```

### Indirect Addressing mode
In this mode data is transferred from the address pointed by the data in a register to other register.
```
MOV A,M ;(data is transferred from the memory location pointed by the register to the accumulator)
```

### Implied Addressing mode
This mode doesn't require any operand.The data is specified by opcode itself.
Eg:-
```
RAL
CMP
```
