Most of the avr chips come from the factory set to divide the system CPU clock by eight. This is done to save power.

To change clock speed we need to burn fuses. The AVR chips have two or three bytes of special memory locations that they call fuse bits. Because they fundamentally alter the way the chip behaves, they are kept away from the main program flash memory, but otherwise they function similarly.

To clear the default CLKDIV8 fuse that divides the internal CPU clock by 8, we need to change lfuse.

Note:- The default fuse values are:
* lfuse = 0x62
* hfuse = 0xDF
* efuse = 0x01

To change the lfuse in avrdude we can use the following command on the command-line.
```
avrdude -U lfuse:w:0xE2:m
```
