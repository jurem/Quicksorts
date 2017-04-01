// Sedgewick's partitions with sentinels on both sides
void FUNNAME(int a[], int left, int right) {
	if (right <= left) return;
	CALLED;
    if GT(a[left], a[right]) swap(a, left, right);
	int p = a[left];
	int l = left, r = right;
	while (1) {
		while LT(a[++l], p);
		while GT(a[--r], p);
		if (l >= r) break;
		SWAP(a, l, r);
	};
	SWAP(a, left, r);
	FUNNAME(a, left, r - 1);
	FUNNAME(a, r + 1, right);
}