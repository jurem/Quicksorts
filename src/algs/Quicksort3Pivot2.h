void FUNNAME(int a[], int left, int right) {
	if (right <= left) return;
	CALLED;
	// p, q, r
	if GT(a[left], a[left+1]) SWAP(a, left, left+1);
	if GT(a[left+1], a[right]) SWAP(a, left+1, right);
	if GT(a[left], a[left+1]) SWAP(a, left, left+1);
    if (right <= left + 2) return;  // avoids unnecessary swaping
	int p = a[left], q = a[left + 1], r = a[right];
	// l, i, j, g
	int l = left + 2, i = l, g = right - 1, j = g;
	while (1) {
		int v = a[i];
		if LT(v, q) {
			if LT(v, p) SWAP(a, l++, i);
			i++;
		} else {
            int u;
            while (LT(q, u = a[j])) {
                if (GT(u, r)) SWAP(a, j, g--);
                j--;
            }
            if (i >= j) break;
            SWAP(a, i, j);
            if LT(u, p) SWAP(a, l++, i);
            if GT(v, r) SWAP(a, j, g--);
            i++;
            j--;
		}
	}
    if (i == j) {
        if GT(a[i], r) SWAP(a, j, g--);
        j--;
    }
    // q -> na pravo mesto (i)
	if (l < i) { SWAP(a, left+1, --i); SWAP(a, left+1, --l); }
	else { SWAP(a, left+1, --i); l--; }
	// p -> na pravo mesto (l)
	SWAP(a, left, --l);
	// r --> na pravo mesto (g)
	SWAP(a, right, ++g);
	FUNNAME(a, left, l - 1);
	FUNNAME(a, l + 1, i - 1);
	FUNNAME(a, i + 1, g - 1);
	FUNNAME(a, g + 1, right);
}
