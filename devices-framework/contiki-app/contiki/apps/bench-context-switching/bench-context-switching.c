#include "bench-context-switching.h"

void bench_init()
{
    // Init the GPIO
    P6SEL &= ~0x08;
    P6DIR |= 0x08;
}

void bench_on()
{
    // Set the GPIO up
    P6OUT |= 0x08;
}

void bench_off()
{
    P6OUT &= ~0x08;
}
