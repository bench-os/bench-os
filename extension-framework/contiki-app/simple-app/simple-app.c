#include "contiki.h"
#include "gpio.h"
#include "sys/clock.h"
#include "bench-context-switching.h"

#include <stdio.h>

#define TASK_1 1
#define TASK_2 2

PROCESS(task_1, "First task");
PROCESS(task_2, "Second task");
AUTOSTART_PROCESSES(&task_1, &task_2);

static struct etimer timer;

PROCESS_THREAD(task_1, ev, data)
{
    PROCESS_BEGIN();

    //GPIO_SOFTWARE_CONTROL(GPIO_PORT_TO_BASE(GPIO_C_NUM), GPIO_PIN_MASK(2));
    //GPIO_SET_OUTPUT(GPIO_PORT_TO_BASE(GPIO_C_NUM), GPIO_PIN_MASK(2));

    while (1)
    {
        bench_ping(TASK_1);
        //GPIO_SET_PIN(GPIO_PORT_TO_BASE(GPIO_C_NUM), GPIO_PIN_MASK(2));
        clock_delay_usec(1000);
        //GPIO_CLR_PIN(GPIO_PORT_TO_BASE(GPIO_C_NUM), GPIO_PIN_MASK(2));
        bench_ping(TASK_1);
        PROCESS_PAUSE();
    }

    PROCESS_END();
}

PROCESS_THREAD(task_2, ev, data)
{
    PROCESS_BEGIN();

    //GPIO_SOFTWARE_CONTROL(GPIO_PORT_TO_BASE(GPIO_C_NUM), GPIO_PIN_MASK(3));
    //GPIO_SET_OUTPUT(GPIO_PORT_TO_BASE(GPIO_C_NUM), GPIO_PIN_MASK(3));

    while (1)
    {
        bench_ping(TASK_2);
        //GPIO_SET_PIN(GPIO_PORT_TO_BASE(GPIO_C_NUM), GPIO_PIN_MASK(3));
        clock_delay_usec(1000);
        //GPIO_CLR_PIN(GPIO_PORT_TO_BASE(GPIO_C_NUM), GPIO_PIN_MASK(3));
        bench_ping(TASK_2);
        PROCESS_PAUSE();
    }

    PROCESS_END();
}
