void FUNNAME(int a[], int left, int right) {
	if (right <= left) return;
	CALLED;
	int p = a[left];
	int k = left;
	for (int i = left + 1; i <= right; i++)
		if LT(a[i], p) SWAP(a, ++k, i);
	SWAP(a, left, k);
	FUNNAME(a, left, k - 1);
	FUNNAME(a, k + 1, right);
}