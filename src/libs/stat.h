#ifndef STAT_H
#define STAT_H

#include "common.h"

typedef struct stat_t {
	// totals
	count_t totalCmps;
	count_t totalMoves;
	count_t totalCalls;
    count_t repeats;
    // average
	double averageCmps;
	double averageMoves;
	double averageCalls; 	
 } stat_t;

void stat_reset(stat_t *s);

void stat_start(stat_t *s);

void stat_stop(stat_t *s);

#endif
