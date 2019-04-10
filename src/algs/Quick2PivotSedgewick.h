void FUN(int a[], int left, int right) {
	if (right <= left) return;
	CALLED;
	int i = left; int i1 = left;
	int j = right; int j1 = right;

	if GT(a[left], a[right]) SWAP(a, left, right);
	int p = a[left];
    int q = a[right];
    
    while (true) {
        bool breakOuterLoop = false;

        i++;
        while LE(a[i], q) {
            if (i >= j) { breakOuterLoop = true; break; }
            if LT(a[i], p) {
                a[i1] = a[i]; i1++; a[i] = a[i1]; MOVE2;
            }
            i++;
        }
        if (breakOuterLoop) break;

        j--;
        while GE(a[j], p) {
            if GT(a[j], q) {
                a[j1] = a[j]; j1--; a[j] = a[j1]; MOVE2;
            }
            if (i >= j) { breakOuterLoop = true; break; }
            j--;
        }
        if (breakOuterLoop) break;

        a[i1] = a[j]; a[j1] = a[i]; MOVE2;
        i1++; j1--;
        a[i] = a[i1]; a[j] = a[j1]; MOVE2;
    }

    a[i1] = p; a[j1] = q; MOVE2;

	FUN(a, left, i1 - 1);
	FUN(a, i1 + 1, j1 - 1);
	FUN(a, j1 + 1, right);
}
