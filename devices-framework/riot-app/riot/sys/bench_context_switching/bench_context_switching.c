#include "bench_context_switching.h"

void bench_init(void)
{
    // Init the GPIO
    gpio_init(GPIO_PIN(PORT_C, 2), GPIO_OUT);
}

void bench_on(void)
{
    // Set the GPIO up
    gpio_set(GPIO_PIN(PORT_C, 2));
}

void bench_off(void)
{
    // Clear the GPIO
    gpio_clear(GPIO_PIN(PORT_C, 2));
}

