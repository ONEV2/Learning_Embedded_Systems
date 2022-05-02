### Watchdog Timers
Watchdog timer can be used to reset the system whenever a timeout occurs. Watchdog has a seperate oscillator and it runs independently of the internal MCU clock.

Before the timeout period occurs, watchdog timer is cleared by software, thus if the software fails to clear the watchdog timer, a high priority system reset is executed, thereby preventing any delay's/errors for a prolonged period of time in a system.

Watchdog timer can also be used to wake system from sleep mode or call an interrupt. 

Since these timers have seperate timers(crystal oscillators), We can easily prescale the clock and get desired reset timer.
