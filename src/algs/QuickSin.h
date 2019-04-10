void FUN(int a[], int left, int right) {
	// p | <= p | ? | >= p
	if (right <= left) return;
	CALLED;
	int p = a[left];
	int l = left, r = right;
	while (++l <= r) {
        if GE(a[l], p) {
            while GT(a[r], p) r--;
            if (l >= r) break;
            SWAP(a, l, r--);
        }
	}
    SWAP(a, left, r);
	FUN(a, left, r - 1);
	FUN(a, r + 1, right);
}