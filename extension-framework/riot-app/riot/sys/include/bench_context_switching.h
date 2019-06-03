#ifndef __BENCH_CONTEXT_SWITCHING_H__
#define __BENCH_CONTEXT_SWITCHING_H__

#include "xtimer.h"
#include "mutex.h"
#include <stdio.h>

#define BENCH_CACHE_SIZE 10

typedef struct BItem
{
    uint32_t from_pid;
    uint32_t to_pid;
    uint32_t ticks;
} BItem_t;

/**
 * Init the benchmark.
 */
int bench_init(void);

/**
 * Ping the benchmark.
 */
void bench_ping(uint32_t id);

/**
 * Check if there was a switching context.
 */
int check_change(void);

/**
 * Flush the bench store.
 */
void bench_flush(void);

#endif
