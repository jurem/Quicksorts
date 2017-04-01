#include <time.h>
#include <limits.h>

#include "timer.h"

void timer_reset(timer_t *t) {
	t->timeStart = t->timeLap = t->timeTotal = 0;
	t->timeAvg = 0;
	t->repeats = 0;
}


double timer_get_s(timer_t *t) {
    return t->timeAvg / CLOCKS_PER_SEC;
}


double timer_get_ms(timer_t *t) {
	return (t->timeAvg * 1000) / CLOCKS_PER_SEC;
}


double timer_get_us(timer_t *t) {
	return (t->timeAvg * 1000 * 1000) / CLOCKS_PER_SEC;
}
