#ifndef __BENCH_CONTEXT_SWITCHING_H__
#define __BENCH_CONTEXT_SWITCHING_H__

#include "board.h"
#include <stdio.h>

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
