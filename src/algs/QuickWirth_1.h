void FUN(int a[], int left, int right) {
    if (right <= left) return;
    CALLED;
	int p = a[left];
	int l = left - 1, r = right + 1;
	while (true) {
		while LT(a[++l], p);
		while GT(a[--r], p);
		if (l >= r) break;
		SWAP(a, l, r);
	};
	FUN(a, left, r);
	FUN(a, r + 1, right);
}

/*
Notice the similarity with Wirth's partition.
*/
