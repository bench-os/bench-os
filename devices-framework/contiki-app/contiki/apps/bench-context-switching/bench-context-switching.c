#include "bench-context-switching.h"

void bench_init()
{
    // Init the GPIO
    P4SEL &= ~0x01;
    P4DIR |= 0x01;
}

void bench_on()
{
    // Set the GPIO up
    P4OUT |= 0x01;
}

void bench_off()
{
    P4OUT &= ~0x01;
}
