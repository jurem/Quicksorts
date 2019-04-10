void FUN(int a[], int left, int right) {
	if (right <= left) return;
	CALLED;
    if GT(a[left], a[right]) swap(a, left, right);
	int p = a[left];
	int l = left, r = right;
	while (true) {
		while LT(a[++l], p);
		while GT(a[--r], p);
		if (l >= r) break;
		SWAP(a, l, r);
	};
	SWAP(a, left, r);
	FUN(a, left, r - 1);
	FUN(a, r + 1, right);
}


/*
Sedgewick's partitions with sentinels on both sides
Notice the similarity with Wirth's partitioning.
*/
