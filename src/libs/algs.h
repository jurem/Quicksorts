#ifndef ALGS_H
#define ALGS_H

#include "common.h"

// globals used for statistics
count_t alg_cmps;
count_t alg_moves;
count_t alg_calls;

typedef void (*SortFun)(int[], int, int);

typedef struct SortInfo {
	const char* name;
	SortFun funtime;
	SortFun funstat;
} SortInfo;

const char* algName(int i);

const SortInfo* findAlg(const char* name);

void printAlgs(const char *prefix);

#endif
