#include "do_undef.h"

#define FUNNAME	CONCAT(time, SORTNAME)

// compares
#define CMP1
#define CMP2
#define CMPN(n)
#define LE(a, b)		((a) <= (b))
#define LT(a, b)		((a) < (b))
#define EQ(a, b)		((a) == (b))
#define GT(a, b)		((a) > (b))
#define GE(a, b)		((a) >= (b))

// moves and swaps
#define MOVE1
#define MOVE2
#define MOVE(a, i, j)	a[i] = a[j]
#define SWAP1
#define SWAP(a, i, j)	swap(a, i, j)

// calls
#define CALLED
