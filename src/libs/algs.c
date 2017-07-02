#include <stdio.h>
#include <string.h>

#include "algs.h"
#include "seq.h"
#include "algs/allalgs.h"


const SortInfo algs[] = {
	{ "Insertion", timeInsertion, statInsertion },
//    { "radix", radix },
	// single-pivot partitions
	{ "QuicksortLomuto", timeQuicksortLomuto, statQuicksortLomuto },
	{ "QuicksortLomutoMoves", timeQuicksortLomutoMoves, statQuicksortLomutoMoves },
	{ "QuicksortHoare",	timeQuicksortHoare, statQuicksortHoare },
	{ "QuicksortHoare1", timeQuicksortHoare1, statQuicksortHoare1 },
	{ "QuicksortSedgewick", timeQuicksortSedgewick, statQuicksortSedgewick },
	{ "QuicksortSedgewickMoves", timeQuicksortSedgewickMoves, statQuicksortSedgewickMoves },
	{ "QuicksortSedgewickSentinels", timeQuicksortSedgewickSentinels, statQuicksortSedgewickSentinels },
	{ "QuicksortWirth", timeQuicksortWirth, statQuicksortWirth },
	{ "QuicksortSin", timeQuicksortSin, statQuicksortSin },
	{ "QuicksortSinSentinels", timeQuicksortSinSentinels, statQuicksortSinSentinels },
	// { "3Way1", qs3Way1 },
	// { "3Way2", qs3Way2 },
	// { "3Way3", qs3Way3 },
	// dual-pivot partitions
	{ "QuicksortYaroSimple", timeQuicksortYaroSimple, statQuicksortYaroSimple },
	{ "QuicksortYaro", timeQuicksortYaro, statQuicksortYaro },
	// triple-pivot partitions
	{ "Quicksort3Pivot0", timeQuicksort3Pivot0, statQuicksort3Pivot0 },
	{ "Quicksort3Pivot1", timeQuicksort3Pivot1, statQuicksort3Pivot1 },
	{ "Quicksort3Pivot2", timeQuicksort3Pivot2, statQuicksort3Pivot2 },
	{ "Quicksort3Pivot3", timeQuicksort3Pivot3, statQuicksort3Pivot3 },
	// { "msIter", msIter },
	{ 0, 0, 0 }
};


const char* algName(int i) {
	return algs[i].name;
}


const SortInfo* findAlg(const char* name) {
	for (int i = 0; algs[i].name != 0; i++)
		if (strcmp(name, algs[i].name) == 0) return &algs[i];
	return 0;
}


void printAlgs(const char *prefix) {
    printf("%s", prefix);
    for (int i = 0; algName(i) != NULL; i++) printf("%s ", algName(i));
    printf("\n");
}
