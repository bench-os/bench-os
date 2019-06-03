#include "bench_context_switching.h"

void bench_init(void)
{
    // Init the GPIO
    P4SEL &= ~0x01;
    P4DIR |= 0x01;
}

void bench_on(void)
{
    // Set the GPIO up
    P4OUT |= 0x01;
}

void bench_off(void)
{
    P4OUT &= ~0x01;
}

