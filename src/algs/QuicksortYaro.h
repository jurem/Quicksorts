void FUNNAME(int a[], int left, int right) {
	// p | < p | p <= . <= q | ? | > q | q
	if (right <= left) return;
	CALLED;
	if GT(a[left], a[right]) SWAP(a, left, right);
	int p = a[left], q = a[right];
	int l = left + 1, k = l, r = right - 1;
	while (k <= r) {
		if LT(a[k], p) SWAP(a, l++, k);
		else if GT(a[k], q) {
			while (GT(a[r], q) && k < r) r--;
			SWAP(a, k, r--);
			if LT(a[k], p) SWAP(a, l++, k);
		}
		k++;
	}
	SWAP(a, --l, left);
	SWAP(a, ++r, right);
	FUNNAME(a, left, l - 1);
	//if LT(a[l], a[r])
    FUNNAME(a, l + 1, r - 1);
	FUNNAME(a, r + 1, right);
}