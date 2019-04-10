void FUN(int a[], int left, int right) {
	if (right <= left) return;
	CALLED;
	int p = a[left];
	int l = left, k = left + 1, r = right;
	while (k <= r) {
		if (LT(a[k], p)) SWAP(a, l++, k++);
		else if (GT(a[k], p)) SWAP(a, k, r--);
		else k++;
	};
	FUN(a, left, l - 1);
	FUN(a, r + 1, right);
}
