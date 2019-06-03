#include "contiki.h"
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

    P6SEL &= ~0x02;
    P6DIR |= 0x02;

    while (1)
    {
        bench_on();
        P6OUT |= 0x02;
        int i;
        for(i = 0; i < 100; i++) {
            printf("1");
        }
        P6OUT &= ~0x02;
        bench_off();
        PROCESS_PAUSE();
    }

    PROCESS_END();
}

PROCESS_THREAD(task_2, ev, data)
{
    PROCESS_BEGIN();

    P6SEL &= ~0x08;
    P6DIR |= 0x08;

    while (1)
    {
        bench_on();
        P6OUT |= 0x08;
        int i;
        for(i = 0; i < 100; i++) {
            printf("1");
        }
        P6OUT &= ~ 0x08;
        bench_off();
        PROCESS_PAUSE();
    }

    PROCESS_END();
}
