## Timers
One can program a micro-controller to turn on or off at a specified time.

If we have a 2Mhz clock signal, then the clock period is 1/2Mhz i.e 0.5usec, now if the system uses a 16-bit free running counter then to count to 2^16 bits it will take around 0.5*(2^16) i.e around 32.78 ms. 

Two techniques can be used to measure the incoming tasks- polling technique and interrupt technique.
In case of polling technique, at each event detection, the corresponding flag must be cleared and a counter must be updated, whereas in case of interrupts, one must write the ISR function which can clear the flag and update the counter.

## Modes of Operation

Each timer channels(Timer0,Timer1 and Timer2) may be set for specific mode of operation: normal,CTC,Fast PWM, and phase correct PWM.

Normal Mode:- It is used to count from 0x00(BOTTOM) to 0xFF(TOP). The normal mode is useful for generating a periodic "clock tick" that can be used to calculate elapsed time or provide delays within the system. 

Clear Timer On Compare Match:- The CTC is used to generate a precision digital waveform such as periodic signals or a single pulse. The user must describe the parameters and key features of the waveform in terms
of Timer 0 ‘‘clock ticks.’’ When a specific key feature is reached within the waveform, the next key
feature may be set into the OCR0 register.
