A performance measure is a quantitative metric that tells us how good and efficient a system is.

**Latency-** It the time between when the I/O device indicated service is required and the time when service is initiated. Latency includes hardware delays in the digital hardware plus computer software delays.

**Bandwidth-** It is the maximum data flow in bytes/second that can be processed by the system. Sometimes the bandwidth is limited by the I/O device, while other times it is limited by computer software.

While interfacing microcontrollers with external I/O devices,the choice of algorithm drastically effects the syncronisation between mcu and I/O devices.

There are 3 general mechanisms to synchronise the mcu with I/O devices
- Blind
- Polling
- Interrupt

**Blind cycle-** In this method software simply waits a fixed amount of time and assumes the I/O will complete before the delay ends.This method is called blind because there is no status information about the I/O device reported to the software.
![working](https://media.giphy.com/media/BwY7rAK4I48T2TIcEF/giphy.gif)

**Polling-** It is method in which a software loop is created that checks for completed status(flag) set by I/O device. For an input device, the software waits until the input device has new data, and then reads it from the input device whereas, For an output device, the software writes data, triggers the output device then waits until the device is finished.
![working](https://media.giphy.com/media/PwcTYVas5UrxUfKb8g/giphy.gif)

**Interrupt-** Interrupt simply means to interfere i.e- when an iterrupts occurs(software/hardware) the cpu holds the task it is currently executing and performs some other task as specified by the interrput,when this task gets completed, CPU picks up its original task from where it left and starts executing it.

![working](https://media.giphy.com/media/NM8tgHyU1fRZqgNqzB/giphy.gif)

[Reference](https://www.edx.org/course/embedded-systems-shape-the-world-multi-threaded-in?index=product&queryID=0028c612ce23764fb8c535c209174fdd&position=1)
