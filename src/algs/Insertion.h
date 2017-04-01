void FUNNAME(int a[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int j = i;
        int p = a[j];
        while (j > left && LT(p, a[j-1])) {
        	a[j] = a[j-1]; 
        	j--;
        	MOVE1;
        }
        a[j] = p;
        MOVE2;
    }
}