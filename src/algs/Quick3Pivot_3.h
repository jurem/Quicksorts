void FUN(int a[], int left, int right) {
	if (right <= left) return;
	CALLED;
	// p, q, r
	if GT(a[left], a[left+1]) SWAP(a, left, left+1);
	if GT(a[left+1], a[right]) SWAP(a, left+1, right);
	if GT(a[left], a[left+1]) SWAP(a, left, left+1);
    if (right <= left + 2) return;
	int p = a[left], q = a[left + 1], r = a[right];
	// l, i, j, g
	int l = left + 2, i = l, g = right - 1, j = g;
    int v, u;
	while (true) {
        while (LT(v = a[i], q)) {
            if (LT(v, p)) SWAP(a, l++, i);
            i++;
        }
        while (GT(u = a[j], q)) {
            if (GT(u, r)) SWAP(a, j, g--);
            j--;
        }
        if (i >= j) break;
        SWAP(a, i, j);
        if LT(u, p) SWAP(a, l++, i);
        if GT(v, r) SWAP(a, j, g--);
        i++; j--;
	}
    if (i == j) {
        if GT(v, r) SWAP(a, j, g--);
        j--;
    }
    // q -> na pravo mesto (i)
	if (l < i) { SWAP(a, left+1, --i); SWAP(a, left+1, --l); }
	else { SWAP(a, left+1, --i); l--; }
	// p -> na pravo mesto (l)
	SWAP(a, left, --l);
	// r --> na pravo mesto (g)
	SWAP(a, right, ++g);
	FUN(a, left, l - 1);
	FUN(a, l + 1, i - 1);
	FUN(a, i + 1, g - 1);
	FUN(a, g + 1, right);
}