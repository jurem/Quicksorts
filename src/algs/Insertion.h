void FUN(int a[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int j = i;
        while (j > left && LT(a[j], a[j-1]))
            SWAP(a, j, j-1);
    }
}