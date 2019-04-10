void FUN(int a[], int left, int right) {
    if (right <= left) return;
    CALLED;
	int p = a[left];
	int l = left, r = right;
	while (l <= r) {
		while LT(a[l], p) l++;
		while GT(a[r], p) r--;
		if (l > r) break;
		SWAP(a, l++, r--);
	}
	FUN(a, left, r);
	FUN(a, l, right);
}


/*
Reference: Niklaus Wirth, Algorithms and data structures
The partition method exhibits a clever use of the pivot as sentinel for the while loops.
I'm not sure if Wirth was the first to present this variant.
*/
