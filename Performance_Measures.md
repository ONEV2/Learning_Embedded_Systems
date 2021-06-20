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
