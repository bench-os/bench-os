#include "contiki.h"
#include "sys/clock.h"
#include "bench-context-switching.h"

#include <stdio.h>

PROCESS(init_task, "Init task");
PROCESS(task_1, "First task");
PROCESS(task_2, "Second task");
AUTOSTART_PROCESSES(&init_task);

PROCESS_THREAD(init_task, ev, data)
{
    PROCESS_BEGIN();

    bench_init();

    process_start(&task_1, NULL);
    process_start(&task_2, NULL);

    PROCESS_END();
}

PROCESS_THREAD(task_1, ev, data)
{
    PROCESS_BEGIN();

    //GPIO_SOFTWARE_CONTROL(GPIO_PORT_TO_BASE(GPIO_C_NUM), GPIO_PIN_MASK(2));
    //GPIO_SET_OUTPUT(GPIO_PORT_TO_BASE(GPIO_C_NUM), GPIO_PIN_MASK(2));

    while (1)
    {
        //GPIO_SET_PIN(GPIO_PORT_TO_BASE(GPIO_C_NUM), GPIO_PIN_MASK(2));
        bench_on();
        clock_delay_usec(1000);
        bench_off();
        //GPIO_CLR_PIN(GPIO_PORT_TO_BASE(GPIO_C_NUM), GPIO_PIN_MASK(2));
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
        //GPIO_SET_PIN(GPIO_PORT_TO_BASE(GPIO_C_NUM), GPIO_PIN_MASK(3));
        bench_on();
        clock_delay_usec(1000);
        bench_off();
        //GPIO_CLR_PIN(GPIO_PORT_TO_BASE(GPIO_C_NUM), GPIO_PIN_MASK(3));
        PROCESS_PAUSE();
    }

    PROCESS_END();
}
