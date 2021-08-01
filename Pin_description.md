## Pin Description
<p align="center")>
  <img src="https://scanftree.com/microprocessor/8085.png">
</p>

### Power supply and clock signals
**VCC,GND,(X1,X2)**
- Power,ground and crystal connection pins.

### Address bus
**A8-A15**
- It carries the most significant 8 bits of the memory/IO address.

### Data bus
**AD0-AD7** 
- Carry lower order 8-bit address as well as data bus.
- The CPU may read or write out data through these lines.

### Control and Status signal
**ALE** - Address Latch Enable
- It is an output signal used to give information of AD0-AD7 contents.
- When pulse goes high it indicates that AD0-AD7 are address.
- When it is low it indicates that the contents are data.
**RD** 
- Read memory or IO device
- It indicates that the selected memory location or I/O device is to be read and that the data bus is ready for accepting data from the memory or I/O device.
**WR**
- Write to memory or IO device
- This indicates that the data on the data bus is ready to be written into the selected memory location or I/O device.
**IO/M** - Select memory or an IO device
- It goes high to indicate an I/O operation.
- It goes low for memory operations.

### Status Signals
- They are used to know the type of current operation of the microprocessor.

### Interrupts and Externally Initiated Operations
- They are the signals initiated by an external device to request processor to do a particular task or work.
**Reset OUT** 
- It indicates CPU is being reset.
- It is used to reset all the connected devices when the microprocessor is reset.
**Reset IN**
- This signal is used to reset the microprocessor.
- The program counter inside the microprocessor is set to zero.

### DMA
- When 2 or more devices are connected to a common bus, to prevent the devices from interfering with each other, the tristate gates are used to disconnect all devices except the one that is communicating at a given instant.
- The CPU is disabled by tri-stating its buses(put to floating state) and the transfer is effected directly by external control circuits.

### Serial I/O ports
**SID** - Serial Input data line
**SOD** - Serial Output data line
