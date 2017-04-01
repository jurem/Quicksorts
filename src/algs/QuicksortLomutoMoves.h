    // p | < p | >= p | ?
void FUNNAME(int a[], int left, int right) {
	if (right <= left) return;
	CALLED;
	int p = a[left];
    int i = left, j = right;
    while (1) {
        while GT(a[j], p) j--;
        if (j <= i) break;
        a[i] = a[j];
        a[j] = a[i+1];
        MOVE2;
        i++;
    }
    a[i] = p;
    MOVE1;
	FUNNAME(a, left, i - 1);
	FUNNAME(a, i + 1, right);
}