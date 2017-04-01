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
	while (i <= j) {
		int v = a[i];
		if LT(v, q) {
			if LT(v, p) SWAP(a, l++, i);
			i++;
		} else {
            if LT(v, r) SWAP(a, i, j--);
            else {
                if (i < j) { SWAP(a, j--, g); SWAP(a, i, g--); }
                else SWAP(a, j--, g--);
            };
		}
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