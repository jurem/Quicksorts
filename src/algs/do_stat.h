#include "do_undef.h"

#define ALG_PREFIX STAT_PREFIX
#define FUN FUN_STAT(ALG_NAME)


// compares
#define CMP1			alg_cmps++
#define CMP2			alg_cmps += 2
#define CMPN(n)			alg_cmps += (n)
#define LE(a, b)		(alg_cmps++, (a) <= (b))
#define LT(a, b)		(alg_cmps++, (a) < (b))
#define EQ(a, b)		(alg_cmps++, (a) == (b))
#define GT(a, b)		(alg_cmps++, (a) > (b))
#define GE(a, b)		(alg_cmps++, (a) >= (b))

// moves and swaps
#define MOVE1			alg_moves++
#define MOVE2			alg_moves += 2
#define MOVE(a, i, j)	(alg_moves++, a[i] = a[j])
#define SWAP1			alg_moves += 3
#define SWAP(a, i, j)	(alg_moves += 3, swap(a, i, j))

// calls
#define CALLED			alg_calls++
