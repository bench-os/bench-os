#include "contiki.h"
#include "gpio.h"
#include "sys/clock.h"

#include <stdio.h>

PROCESS(task_1, "First task");
PROCESS(task_2, "Second task");
AUTOSTART_PROCESSES(&task_1, &task_2);

PROCESS_THREAD(task_1, ev, data)
{
    PROCESS_BEGIN();

    GPIO_SOFTWARE_CONTROL(GPIO_PORT_TO_BASE(GPIO_C_NUM), GPIO_PIN_MASK(2));
    GPIO_SET_OUTPUT(GPIO_PORT_TO_BASE(GPIO_C_NUM), GPIO_PIN_MASK(2));

    while (1)
    {
        GPIO_SET_PIN(GPIO_PORT_TO_BASE(GPIO_C_NUM), GPIO_PIN_MASK(2));
        clock_delay_usec(1000);
        GPIO_CLR_PIN(GPIO_PORT_TO_BASE(GPIO_C_NUM), GPIO_PIN_MASK(2));
        PROCESS_PAUSE();
    }

    PROCESS_END();
}

PROCESS_THREAD(task_2, ev, data)
{
    PROCESS_BEGIN();

    GPIO_SOFTWARE_CONTROL(GPIO_PORT_TO_BASE(GPIO_C_NUM), GPIO_PIN_MASK(3));
    GPIO_SET_OUTPUT(GPIO_PORT_TO_BASE(GPIO_C_NUM), GPIO_PIN_MASK(3));

    while (1)
    {
        GPIO_SET_PIN(GPIO_PORT_TO_BASE(GPIO_C_NUM), GPIO_PIN_MASK(3));
        clock_delay_usec(1000);
        GPIO_CLR_PIN(GPIO_PORT_TO_BASE(GPIO_C_NUM), GPIO_PIN_MASK(3));
        PROCESS_PAUSE();
    }

    PROCESS_END();
}
