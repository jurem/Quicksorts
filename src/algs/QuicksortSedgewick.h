// Sedgewick's partition
void FUNNAME(int a[], int left, int right) {
	if (right <= left) return;
	CALLED;
	int p = a[left];
	int l = left, r = right + 1;
	while (1) {
		while LT(a[++l], p) if (l == right) break;
		while GT(a[--r], p);
		if (l >= r) break;
		SWAP(a, l, r);
	};
	SWAP(a, left, r);
	FUNNAME(a, left, r - 1);
	FUNNAME(a, r + 1, right);
}
