#ifndef __BENCH_CONTEXT_SWITCHING_H__
#define __BENCH_CONTEXT_SWITCHING_H__

#include "contiki.h"
#include "dev/serial-line.h"
#include "gpio.h"
#include "board.h"
#include "sys/clock.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char* BENCH_CONTEXT_SWITCHING_FLAG = "[BENCH_CONTEXT_SWITCHING]";
uint32_t bench_context_switching_cache_size;
uint32_t bench_context_switching_cache_index;
uint32_t * bench_context_switching_cache;

/**
 * Init the framework with the GPIO.
 */
void bench_init(uint32_t);

int bench_check_data(char*);

/**
 * Set the GPIO on.
 */
void bench_on(uint32_t);

/**
 * Set the GPIO off.
 */
void bench_off();

/**
 * Ping the benchmark.
 */
void bench_ping(uint32_t id);

/**
 * Check if there was a switching context.
 */
int check_change(void);

#endif
