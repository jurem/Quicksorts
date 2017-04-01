void FUNNAME(int a[], int left, int right) {
    if (right <= left) return;
    CALLED;
	int p = a[left];
	int l = left - 1, r = right + 1;
	while (1) {
		while LT(a[++l], p);
		while GT(a[--r], p);
		if (l >= r) break;
		SWAP(a, l, r);
	};
	FUNNAME(a, left, r);
	FUNNAME(a, r + 1, right);
}
