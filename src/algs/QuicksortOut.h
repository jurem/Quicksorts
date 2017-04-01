void FUNNAME(int a[], int left, int right) {
/*	int* b = (int*)malloc(length * sizeof(int));
	CONCAT(FUNNAME, 2)(a, b, left, right);
*/
}

int* CONCAT(FUNNAME, 2)(int a[], int b[], int left, int right) {
	if (right <= left) return a;
	CALLED;
	int p = a[left];
	MOVE1;
	int l = left;
	int r = right;
	for (int i = left + 1; i <= right; i++) {
		if LT(a[i], p) b[l++] = a[i]; 
		else b[r--] = a[i];
		MOVE1;
	}
	b[l] = p;
	MOVE1;
	CONCAT(FUNNAME, 2)(b, a, left, l - 1);
	CONCAT(FUNNAME, 2)(b, a, r + 1, right);	
}