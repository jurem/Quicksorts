#ifndef ALLALGS_H
#define ALLALGS_H

// double macro expansion trick
// see http://stackoverflow.com/questions/1597007/creating-c-macro-with-and-line-token-concatenation-with-positioning-macr
#define CONCAT1(x, y) x ## y
#define CONCAT(x, y) CONCAT1(x, y)
//
#define CONCAT3(x, y, z) CONCAT(CONCAT(x, y), z)


// **************** Straight sorts

#define SORTNAME Insertion
#include "do_time.h"
#include "Insertion.h"
#include "do_stat.h"
#include "Insertion.h"
#undef SORTNAME


// **************** Lomuto's partitions
// p | < p | >= p | ?

#define SORTNAME QuicksortLomuto
#include "do_time.h"
#include "QuicksortLomuto.h"
#include "do_stat.h"
#include "QuicksortLomuto.h"
#undef SORTNAME


#define SORTNAME QuicksortLomutoMoves
#include "do_time.h"
#include "QuicksortLomutoMoves.h"
#include "do_stat.h"
#include "QuicksortLomutoMoves.h"
#undef SORTNAME


// **************** Crossing pointer partitions
// p | <= p | ? | >= p

#define SORTNAME QuicksortHoare
#include "do_time.h"
#include "QuicksortHoare.h"
#include "do_stat.h"
#include "QuicksortHoare.h"
#undef SORTNAME


#define SORTNAME QuicksortHoare1
#include "do_time.h"
#include "QuicksortHoare1.h"
#include "do_stat.h"
#include "QuicksortHoare1.h"
#undef SORTNAME


#define SORTNAME QuicksortSedgewick
#include "do_time.h"
#include "QuicksortSedgewick.h"
#include "do_stat.h"
#include "QuicksortSedgewick.h"
#undef SORTNAME


#define SORTNAME QuicksortSedgewickMoves
#include "do_time.h"
#include "QuicksortSedgewickMoves.h"
#include "do_stat.h"
#include "QuicksortSedgewickMoves.h"
#undef SORTNAME


#define SORTNAME QuicksortSedgewickSentinels
#include "do_time.h"
#include "QuicksortSedgewickSentinels.h"
#include "do_stat.h"
#include "QuicksortSedgewickSentinels.h"
#undef SORTNAME


#define SORTNAME QuicksortWirth
#include "do_time.h"
#include "QuicksortWirth.h"
#include "do_stat.h"
#include "QuicksortWirth.h"
#undef SORTNAME


#define SORTNAME QuicksortSin
#include "do_time.h"
#include "QuicksortSin.h"
#include "do_stat.h"
#include "QuicksortSin.h"
#undef SORTNAME


#define SORTNAME QuicksortSinSentinels
#include "do_time.h"
#include "QuicksortSinSentinels.h"
#include "do_stat.h"
#include "QuicksortSinSentinels.h"
#undef SORTNAME


// insert here 3-way partitions
#define SORTNAME QuicksortTripartiteSimple
#include "do_time.h"
#include "QuicksortTripartiteSimple.h"
#include "do_stat.h"
#include "QuicksortTripartiteSimple.h"
#undef SORTNAME

#define SORTNAME QuicksortTripartiteBentleyMcIlroy
#include "do_time.h"
#include "QuicksortTripartiteBentleyMcIlroy.h"
#include "do_stat.h"
#include "QuicksortTripartiteBentleyMcIlroy.h"
#undef SORTNAME


// **************** Dual-pivot partitions

#define SORTNAME QuicksortSedgewickDualPivot
#include "do_time.h"
#include "QuicksortSedgewickDualPivot.h"
#include "do_stat.h"
#include "QuicksortSedgewickDualPivot.h"
#undef SORTNAME

#define SORTNAME QuicksortYaroSimple
#include "do_time.h"
#include "QuicksortYaroSimple.h"
#include "do_stat.h"
#include "QuicksortYaroSimple.h"
#undef SORTNAME


#define SORTNAME QuicksortYaro
#include "do_time.h"
#include "QuicksortYaro.h"
#include "do_stat.h"
#include "QuicksortYaro.h"
#undef SORTNAME

// **************** Triple-pivot partitions

#define SORTNAME Quicksort3Pivot0
#include "do_time.h"
#include "Quicksort3Pivot0.h"
#include "do_stat.h"
#include "Quicksort3Pivot0.h"
#undef SORTNAME

#define SORTNAME Quicksort3Pivot1
#include "do_time.h"
#include "Quicksort3Pivot1.h"
#include "do_stat.h"
#include "Quicksort3Pivot1.h"
#undef SORTNAME

#define SORTNAME Quicksort3Pivot2
#include "do_time.h"
#include "Quicksort3Pivot2.h"
#include "do_stat.h"
#include "Quicksort3Pivot2.h"
#undef SORTNAME

#define SORTNAME Quicksort3Pivot3
#include "do_time.h"
#include "Quicksort3Pivot3.h"
#include "do_stat.h"
#include "Quicksort3Pivot3.h"
#undef SORTNAME

// **************** Out-place quicksort

#define SORTNAME QuicksortOut
#include "do_time.h"
#include "QuicksortOut.h"
#include "do_stat.h"
#include "QuicksortOut.h"
#undef SORTNAME
#endif
