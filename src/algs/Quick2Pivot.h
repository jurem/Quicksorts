void FUN(int a[], int left, int right) {
	// p | < p | p <= . <= q | ? | > q | q
	if (right <= left) return;
	CALLED;
	if GT(a[left], a[right]) SWAP(a, left, right);
	int p = a[left], q = a[right];
	int l = left + 1, k = l, r = right - 1;
	while (k <= r) {
		if LT(a[k], p) SWAP(a, l++, k++);
		else if GT(a[k], q)	SWAP(a, k, r--);
		else k++;
	}
	SWAP(a, left, --l);
	SWAP(a, ++r, right);
	FUN(a, left, l - 1);
	//if LT(a[l], a[r])
    FUN(a, l + 1, r - 1);
	FUN(a, r + 1, right);
}