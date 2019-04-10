void FUN(int a[], int left, int right) {
	if (right <= left) return;
	CALLED;
	int p = a[left];
	int l = left, r = right + 1;
	while (true) {
		while LE(a[++l], p) if (l == right) break;
		while GE(a[--r], p) if (r == left) break;
		if (l >= r) break;
		SWAP(a, l, r);
	};
	SWAP(a, left, r);
	FUN(a, left, r - 1);
	FUN(a, r + 1, right);
}


/*
Reference: C. A. R. Hoare, Quicksort, 1962. The Computer Journal, Volume 5, Issue 1, 1962, Pages 10–16, https://doi.org/10.1093/comjnl/5.1.10

Partition:
* Hoare describe a partition where the comparisons are <= and >=.
* The final step of the partition is to put (swap) the pivot to the correct place.
* The resulting size of left and right partition is n-1 in total.
Other:
- describes also the variant with moves instead of swaps
- describes also the variant with sentinels
*/
