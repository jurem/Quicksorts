void FUNNAME(int a[], int left, int right) {
	if (right <= left) return;
	CALLED;
	int p = a[left];
	int l = left, r = right; // Originally i, j and f (first), l (last)
	while (l <= r) {
		while (GE(a[r], p) && r >= left) r--;
		while (LT(a[l], p) && l <= right) l++;
		if (l < r) {
			SWAP(a, l, r);
			l++;
			r--;
		}
	};
	// After partition, we can call QUICKSORT on the array A[left] through A[l - 1], which is S_1,
	// and on the array A[r + 1] through A[right], which is (S_2 u S_3).
	// However, if l == left in which case S_1 = {}, we must first remove at least one instance of a from (S_2 u S_3).
	// It is convenient to remove the element on which we partitioned.
	if (l == left) r++;
	FUNNAME(a, left, l - 1); // S_1 with indices left, ..., l - 1
	FUNNAME(a, r + 1, right); // (S_2 u S_3) with indices r + 1, ..., right
}
