void FUNNAME(int a[], int left, int right) {
	if (right <= left) return;
	CALLED;
	int p = a[left];
	int l = left, i = left, j = right + 1, r = j;
	while (1) {
		while (LT(a[++i], p) && i < right) {}
		while (GT(a[--j], p)) {}
		if (i >= j) break;

		SWAP(a, i, j);

		if (EQ(a[i], p)) SWAP(a, ++l, i);
		if (EQ(a[j], p)) SWAP(a, --r, j);
	};

	i = j + 1;
	for (int k = left; k <= l; k++) SWAP(a, k, j--);
	for (int k = right; k >= r; k--) SWAP(a, k, i++);

	FUNNAME(a, left, j);
	FUNNAME(a, i, right);
}
