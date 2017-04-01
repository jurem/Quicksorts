#include "stat.h"

extern count_t alg_cmps, alg_moves, alg_calls;


void stat_reset(stat_t *s) {
	alg_cmps = alg_moves = alg_calls = 0;
	s->totalCmps = s->totalMoves = s->totalCalls = 0;
	s->repeats = 0;
	s->averageCmps = s->averageMoves = s->averageCalls = 0;
 }


void stat_start(stat_t *s) {
	alg_cmps = alg_moves = alg_calls = 0;
}


void stat_stop(stat_t *s) {
	s->totalCmps += alg_cmps;
	s->totalMoves += alg_moves;
	s->totalCalls += alg_calls;
	s->repeats++;
	s->averageCmps = (double) s->totalCmps / s->repeats;
	s->averageMoves = (double) s->totalMoves / s->repeats;
	s->averageCalls = (double) s->totalCalls / s->repeats;
}
