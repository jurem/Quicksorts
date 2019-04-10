void FUN(int a[], int left, int right) {
	if (right <= left) return;
	CALLED;
	int p = a[left];
	int l = left, r = right + 1;
	while (true) {
		while LT(a[++l], p) if (l == right) break;
		while GT(a[--r], p);
		if (l >= r) break;
		SWAP(a, l, r);
	};
	SWAP(a, left, r);
	FUN(a, left, r - 1);
	FUN(a, r + 1, right);
}


/*
Sedgewick's partition from the
* Sedgewick, Bentyle, Quicksort is optimal (They use the right pivot).

References:
* Sedgewick lectures: sometimes the second loop includes the index r underflow.

References
* Sedgewick, Implementing Quicksort Programs
* Sedgewick, The analysis of Quicksort Programs
include the sentinel a[n]=inf in the array.

*/