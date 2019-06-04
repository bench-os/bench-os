#include "bench_context_switching.h"

void bench_init(void)
{
    // Init the GPIO
    P6SEL &= ~0x08;
    P6DIR |= 0x08;
}

void bench_on(void)
{
    // Set the GPIO up
    P6OUT |= 0x08;
}

void bench_off(void)
{
    P6OUT &= ~0x08;
}

