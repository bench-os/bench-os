#ifndef __BENCH_CONTEXT_SWITCHING_H__
#define __BENCH_CONTEXT_SWITCHING_H__

#include "contiki.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Init the framework
 */
void bench_init();

/**
 * Set the GPIO on.
 */
void bench_on();

/**
 * Set the GPIO off.
 */
void bench_off();

#endif
