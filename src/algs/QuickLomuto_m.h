// p | < p | >= p | ?
void FUN(int a[], int left, int right) {
	if (right <= left) return;
	CALLED;
	int p = a[left];
    int i = left, j = right;
    while (true) {
        while GT(a[j], p) j--;
        if (j <= i) break;
        a[i] = a[j];
        a[j] = a[i + 1];
        MOVE2;
        i++;
    }
    a[i] = p;
    MOVE1;
	FUN(a, left, i - 1);
	FUN(a, i + 1, right);
}