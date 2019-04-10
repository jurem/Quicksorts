#include <stdio.h>
#include <string.h>

#include "algs.h"
#include "seq.h"
#include "algs/allalgs.h"


const SortInfo algs[] = {
	{ "Insertion", time_Insertion, stat_Insertion },
	{ "Insertion_m", time_Insertion_m, stat_Insertion_m },
//    { "radix", radix },
	// single-pivot partitions
	{ "QuickLomuto", time_QuickLomuto, stat_QuickLomuto },
	{ "QuickLomuto_m", time_QuickLomuto_m, stat_QuickLomuto_m },
	{ "QuickHoare",	time_QuickHoare, stat_QuickHoare },
	{ "QuickWirth", time_QuickWirth, stat_QuickWirth },
	{ "QuickWirth_1", time_QuickWirth_1, stat_QuickWirth_1 },
	{ "QuickSedgewick", time_QuickSedgewick, stat_QuickSedgewick },
	{ "QuickSedgewick_m", time_QuickSedgewick_m, stat_QuickSedgewick_m },
	{ "QuickSedgewick_s", time_QuickSedgewick_s, stat_QuickSedgewick_s },
    // 3-way single-pivot partitions
	{ "Quick3Way", time_Quick3Way, stat_Quick3Way },
	{ "Quick3WayBentleyMcIlroy", time_Quick3WayBentleyMcIlroy, stat_Quick3WayBentleyMcIlroy },
	// dual-pivot partitions
	{ "Quick2PivotSedgewick", time_Quick2PivotSedgewick, stat_Quick2PivotSedgewick },
	{ "Quick2Pivot", time_Quick2Pivot, stat_Quick2Pivot },
	{ "Quick2PivotYaroslavsky", time_Quick2PivotYaroslavsky, stat_Quick2PivotYaroslavsky },
	// triple-pivot partitions
	{ "Quick3Pivot_0", time_Quick3Pivot_0, stat_Quick3Pivot_0 },
	{ "Quick3Pivot_1", time_Quick3Pivot_1, stat_Quick3Pivot_1 },
	{ "Quick3Pivot_2", time_Quick3Pivot_2, stat_Quick3Pivot_2 },
	{ "Quick3Pivot_3", time_Quick3Pivot_3, stat_Quick3Pivot_3 },
	// other
	{ "QuickSin", time_QuickSin, stat_QuickSin },
	{ "QuickSin_s", time_QuickSin_s, stat_QuickSin_s },
	{ "QuickAHU", time_QuickAHU, stat_QuickAHU },
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
