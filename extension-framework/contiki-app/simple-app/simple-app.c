#include "contiki.h"
#include "bench-context-switching.h"

#include <stdio.h>

#define TASK_1 1
#define TASK_2 2

PROCESS(task_1, "First task");
PROCESS(task_2, "Second task");
AUTOSTART_PROCESSES(&task_1, &task_2);

PROCESS_THREAD(task_1, ev, data)
{
    PROCESS_BEGIN();

    //P6SEL &= ~0x02;
    //P6DIR |= 0x02;

    while (1)
    {
        bench_ping(TASK_1);
        //P6OUT |= 0x02;
        int i;
        for(i = 0; i < 100; i++) {
            printf("1\n");
        }
        //P6OUT &= ~0x02;
        bench_ping(TASK_1);
        PROCESS_PAUSE();
    }

    PROCESS_END();
}

PROCESS_THREAD(task_2, ev, data)
{
    PROCESS_BEGIN();

    //P6SEL &= ~0x08;
    //P6DIR |= 0x08;

    while (1)
    {
        bench_ping(TASK_2);
        //P6OUT |= 0x08;
        int i;
        for(i = 0; i < 100; i++) {
            printf("1\n");
        }
        //P6OUT &= ~ 0x08;
        bench_ping(TASK_2);
        PROCESS_PAUSE();
    }

    PROCESS_END();
}
