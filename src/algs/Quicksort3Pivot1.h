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
        if LT(a[i], p) SWAP(a, l++, i);
        else if GT(a[i], q) {
            while (i <= j) {
                if GT(a[j], r) SWAP(a, j--, g--);
                else if GT(a[j], q) j--;
                else break;
            }
            // a[i] >= q, a[j] <= q
            if (i >= j) break;
            SWAP(a, i, j);
            if LT(a[i], p) SWAP(a, l++, i);
            if GT(a[j], r) SWAP(a, j, g--);
            j--;
		}
        i++;
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