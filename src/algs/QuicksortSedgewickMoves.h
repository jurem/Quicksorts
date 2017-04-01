// Sedgewick's partition with moves
void FUNNAME(int a[], int left, int right) {
	if (right <= left) return;
	CALLED;
    if GT(a[left], a[right]) swap(a, left, right);
    int p = a[left];
    int l = left, r = right;
    while (1) {
        while GT(a[--r], p);
        a[l] = a[r];
        MOVE1;
        while LT(a[++l], p);
        if (l >= r) break;
        a[r] = a[l];
        MOVE1;
    }
    if LE(a[r+1], p) r++;
    a[r] = p;
    MOVE1;
	FUNNAME(a, left, r - 1);
	FUNNAME(a, r + 1, right);
}