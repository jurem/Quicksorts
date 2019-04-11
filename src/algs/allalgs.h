#ifndef ALLALGS_H
#define ALLALGS_H

// double macro expansion trick
// see http://stackoverflow.com/questions/1597007/creating-c-macro-with-and-line-token-concatenation-with-positioning-macr
#define CONCAT1(x, y) x ## y
#define CONCAT(x, y) CONCAT1(x, y)
//
#define CONCAT3(x, y, z) CONCAT(CONCAT(x, y), z)

#define	TIME_PREFIX time_
#define	STAT_PREFIX stat_
#define FUN_NAME(prefix, name) CONCAT(prefix, name)
#define FUN_TIME(name) FUN_NAME(TIME_PREFIX, name)
#define FUN_STAT(name) FUN_NAME(STAT_PREFIX, name)


// **************** Insertion sort

#define ALG_NAME Insertion
#include "do_time.h"
#include "Insertion.h"
#include "do_stat.h"
#include "Insertion.h"
#undef ALG_NAME

#define ALG_NAME Insertion_m
#include "do_time.h"
#include "Insertion_m.h"
#include "do_stat.h"
#include "Insertion_m.h"
#undef ALG_NAME

// **************** Quicksort single pivot partitions

#define ALG_NAME QuickLomuto
#include "do_time.h"
#include "QuickLomuto.h"
#include "do_stat.h"
#include "QuickLomuto.h"
#undef ALG_NAME

#define ALG_NAME QuickLomuto_m
#include "do_time.h"
#include "QuickLomuto_m.h"
#include "do_stat.h"
#include "QuickLomuto_m.h"
#undef ALG_NAME

#define ALG_NAME QuickHoare
#include "do_time.h"
#include "QuickHoare.h"
#include "do_stat.h"
#include "QuickHoare.h"
#undef ALG_NAME

#define ALG_NAME QuickWirth
#include "do_time.h"
#include "QuickWirth.h"
#include "do_stat.h"
#include "QuickWirth.h"
#undef ALG_NAME

#define ALG_NAME QuickWirth_1
#include "do_time.h"
#include "QuickWirth_1.h"
#include "do_stat.h"
#include "QuickWirth_1.h"
#undef ALG_NAME

#define ALG_NAME QuickSedgewick
#include "do_time.h"
#include "QuickSedgewick.h"
#include "do_stat.h"
#include "QuickSedgewick.h"
#undef ALG_NAME

#define ALG_NAME QuickSedgewick_m
#include "do_time.h"
#include "QuickSedgewick_m.h"
#include "do_stat.h"
#include "QuickSedgewick_m.h"
#undef ALG_NAME

#define ALG_NAME QuickSedgewick_s
#include "do_time.h"
#include "QuickSedgewick_s.h"
#include "do_stat.h"
#include "QuickSedgewick_s.h"
#undef ALG_NAME

// **************** Quicksort 3-way partitions

#define ALG_NAME Quick3Way
#include "do_time.h"
#include "Quick3Way.h"
#include "do_stat.h"
#include "Quick3Way.h"
#undef ALG_NAME

#define ALG_NAME Quick3WayBentleyMcIlroy
#include "do_time.h"
#include "Quick3WayBentleyMcIlroy.h"
#include "do_stat.h"
#include "Quick3WayBentleyMcIlroy.h"
#undef ALG_NAME

// **************** Dual-pivot partitions

#define ALG_NAME Quick2PivotSedgewick
#include "do_time.h"
#include "Quick2PivotSedgewick.h"
#include "do_stat.h"
#include "Quick2PivotSedgewick.h"
#undef ALG_NAME

#define ALG_NAME Quick2Pivot
#include "do_time.h"
#include "Quick2Pivot.h"
#include "do_stat.h"
#include "Quick2Pivot.h"
#undef ALG_NAME


#define ALG_NAME Quick2PivotYaroslavsky
#include "do_time.h"
#include "Quick2PivotYaroslavsky.h"
#include "do_stat.h"
#include "Quick2PivotYaroslavsky.h"
#undef ALG_NAME

// **************** Triple-pivot partitions

#define ALG_NAME Quick3Pivot_0
#include "do_time.h"
#include "Quick3Pivot_0.h"
#include "do_stat.h"
#include "Quick3Pivot_0.h"
#undef ALG_NAME

#define ALG_NAME Quick3Pivot_1
#include "do_time.h"
#include "Quick3Pivot_1.h"
#include "do_stat.h"
#include "Quick3Pivot_1.h"
#undef ALG_NAME

#define ALG_NAME Quick3Pivot_2
#include "do_time.h"
#include "Quick3Pivot_2.h"
#include "do_stat.h"
#include "Quick3Pivot_2.h"
#undef ALG_NAME

#define ALG_NAME Quick3Pivot_3
#include "do_time.h"
#include "Quick3Pivot_3.h"
#include "do_stat.h"
#include "Quick3Pivot_3.h"
#undef ALG_NAME

// **************** Other

#define ALG_NAME QuickSin
#include "do_time.h"
#include "QuickSin.h"
#include "do_stat.h"
#include "QuickSin.h"
#undef ALG_NAME

#define ALG_NAME QuickSin_s
#include "do_time.h"
#include "QuickSin_s.h"
#include "do_stat.h"
#include "QuickSin_s.h"
#undef ALG_NAME

#define ALG_NAME QuickAHU
#include "do_time.h"
#include "QuickAHU.h"
#include "do_stat.h"
#include "QuickAHU.h"
#undef ALG_NAME


#endif
