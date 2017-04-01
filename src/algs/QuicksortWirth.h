// <= p | ? | >= p
void FUNNAME(int a[], int left, int right) {
	if (right <= left) return;
	CALLED;
	int p = a[left];
	int l = left, r = right;
	while (l <= r) {
		while LT(a[l], p) l++;
		while GT(a[r], p) r--;
		if (l > r) break;
		SWAP(a, l++, r--);
	}
	FUNNAME(a, left, r);
	FUNNAME(a, l, right);
}


/*
another variant from
http://www.roseindia.net/java/beginners/arrayexamples/QuickSort.shtml


public static void quick_srt(int array[],int low, int n){
  int lo = low;
  int hi = n;
  if (lo >= n) {
  return;
  }
  int mid = array[(lo + hi) / 2];
  while (lo < hi) {
  while (lo<hi && array[lo] < mid) {
  lo++;
  }
  while (lo<hi && array[hi] > mid) {
  hi--;
  }
  if (lo < hi) {
  int T = array[lo];
  array[lo] = array[hi];
  array[hi] = T;
  }
  }
  if (hi < lo) {
  int T = hi;
  hi = lo;
  lo = T;
  }
  quick_srt(array, low, lo);
  quick_srt(array, lo == low ? lo+1 : lo, n);
  }
}

*/