#include <stdio.h>
#include <string.h>
#include "thread.h"
#include "board.h"

// Thread stacks
char task1_stack[THREAD_STACKSIZE_MAIN];
char task2_stack[THREAD_STACKSIZE_MAIN];

void *task1(void *arg)
{
    (void)arg;

    while (1)
    {
        // Set GPIO P6.1
        //gpio_set(GPIO_PIN(6, 1));
        P6OUT |= 0x02;
        for(int i = 0; i < 100; i++) {
            puts("1");
        }
        // Clear GPIO P6.1
        //gpio_clear(GPIO_PIN(6, 1));
        P6OUT &= ~0x02;
        thread_yield();
    }
    return NULL;
}

void *task2(void *arg)
{
    (void)arg;

    while (1)
    {
        // Set GPIO P6.3
        //gpio_set(GPIO_PIN(6, 3));
        P6OUT |= 0x08;
        for(int i = 0; i < 100; i++) {
            puts("1");
        }
        // Clear GPIO P6.3
        //gpio_clear(GPIO_PIN(6, 3));
        P6OUT &= ~ 0x08;
        thread_yield();
    }
    return NULL;
}

int main(void)
{
    puts("Simple application");

    // Enable P6.1 and P6.3
    P6SEL &= ~0x0A;
    P6DIR |= 0x0A;


    // Create threadA with priority 1
    puts("Main: Creating task1...");
    thread_create(task1_stack, sizeof(task1_stack),
                  THREAD_PRIORITY_MAIN - 1, THREAD_CREATE_WOUT_YIELD,
                  task1, NULL, "task1");

    // Create threadB with priority 6
    puts("Main: Creating task1...");
    thread_create(task2_stack, sizeof(task2_stack),
                  THREAD_PRIORITY_MAIN - 1, THREAD_CREATE_WOUT_YIELD,
                  task2, NULL, "task2");

    return 0;
}
