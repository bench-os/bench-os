#include "contiki.h"

#include <stdio.h>

PROCESS(task_1, "First task");
PROCESS(task_2, "Second task");
AUTOSTART_PROCESSES(&task_1, &task_2);

PROCESS_THREAD(task_1, ev, data)
{
    PROCESS_BEGIN();

    //GPIO_SOFTWARE_CONTROL(GPIO_PORT_TO_BASE(GPIO_C_NUM), GPIO_PIN_MASK(2));
    //GPIO_SET_OUTPUT(GPIO_PORT_TO_BASE(GPIO_C_NUM), GPIO_PIN_MASK(2));
    P6SEL &= ~0x02;
    P6DIR |= 0x02;

    while (1)
    {
        //GPIO_SET_PIN(GPIO_PORT_TO_BASE(GPIO_C_NUM), GPIO_PIN_MASK(2));
        P6OUT |= 0x02;
        int i;
        for(i = 0; i < 100; i++) {
            printf("1");
        }
        //GPIO_CLR_PIN(GPIO_PORT_TO_BASE(GPIO_C_NUM), GPIO_PIN_MASK(2));
        P6OUT &= ~0x02;
        PROCESS_PAUSE();
    }

    PROCESS_END();
}

PROCESS_THREAD(task_2, ev, data)
{
    PROCESS_BEGIN();

    //GPIO_SOFTWARE_CONTROL(GPIO_PORT_TO_BASE(GPIO_C_NUM), GPIO_PIN_MASK(3));
    //GPIO_SET_OUTPUT(GPIO_PORT_TO_BASE(GPIO_C_NUM), GPIO_PIN_MASK(3));
    P6SEL &= ~0x08;
    P6DIR |= 0x08;

    while (1)
    {
        //GPIO_SET_PIN(GPIO_PORT_TO_BASE(GPIO_C_NUM), GPIO_PIN_MASK(3));
        P6OUT |= 0x08;
        int i;
        for(i = 0; i < 100; i++) {
            printf("1");
        }
        //GPIO_CLR_PIN(GPIO_PORT_TO_BASE(GPIO_C_NUM), GPIO_PIN_MASK(3));
        P6OUT &= ~ 0x08;
        PROCESS_PAUSE();
    }

    PROCESS_END();
}
