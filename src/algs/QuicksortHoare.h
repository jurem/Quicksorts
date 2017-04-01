// TODO: check if this is really original Hoare
void FUNNAME(int a[], int left, int right) {
	if (right <= left) return;
	CALLED;
	int p = a[left];
	int l = left, r = right + 1;
	while (1) {
		while LE(a[++l], p) if (l == right) break;
		while GE(a[--r], p) if (r == left) break;
		if (l >= r) break;
		SWAP(a, l, r);
	};
	SWAP(a, left, r);
	FUNNAME(a, left, r - 1);
	FUNNAME(a, r + 1, right);
}
