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