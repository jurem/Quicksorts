void FUN(int a[], int left, int right) {
	if (right <= left) return;
	CALLED;
	int p = a[left];
	int l = left, i = l, j = right + 1, r = j;
	while (true) {
		while (LT(a[++i], p) && i < right);
		while (GT(a[--j], p));
		if (i >= j) break;
		SWAP(a, i, j);
		if (EQ(a[i], p)) SWAP(a, ++l, i);
		if (EQ(a[j], p)) SWAP(a, --r, j);
	};
	i = j + 1;
	for (int k = left; k <= l; k++) SWAP(a, k, j--);
	for (int k = right; k >= r; k--) SWAP(a, k, i++);
	FUN(a, left, j);
	FUN(a, i, right);
}

/*
Bentley, McIlroy: 3-way partitionig scheme where elements equal to pivot
are put in the left and the right part of the table.
*/