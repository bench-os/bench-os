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
        gpio_set(GPIO_PIN(PORT_C, 2));
        for(int i = 0; i < 1000; i++) {}
        thread_yield();
        gpio_clear(GPIO_PIN(PORT_C, 2));
    }
    return NULL;
}

void *task2(void *arg)
{
    (void)arg;

    while (1)
    {
        gpio_set(GPIO_PIN(PORT_C, 3));
        for(int i = 0; i < 1000; i++) {}
        thread_yield();
        gpio_clear(GPIO_PIN(PORT_C, 3));
    }
    return NULL;
}

int main(void)
{
    puts("Simple application");

    if (gpio_init(GPIO_PIN(PORT_C, 2), GPIO_OUT))
    {
        puts("Error with PC2");
    }
    if (gpio_init(GPIO_PIN(PORT_C, 3), GPIO_OUT))
    {
        puts("Error with PC3");
    }

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
