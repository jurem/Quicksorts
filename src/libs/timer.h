#ifndef TIMER_H
#define TIMER_H

#include "common.h"

typedef struct timer_t {
	clock_t timeStart, timeLap, timeTotal;
	double timeAvg;
	count_t repeats;
} timer_t;

void timer_reset(timer_t *t);

inline void timer_start(timer_t *t) {
	t->timeStart = clock();
}

inline void timer_stop(timer_t *t) {
	t->timeLap = clock() - t->timeStart;
	t->timeTotal += t->timeLap;
	t->timeAvg = (double) t->timeTotal / ++t->repeats;
}

double timer_get_s(timer_t *t);

double timer_get_ms(timer_t *t);

double timer_get_us(timer_t *t);

#endif
