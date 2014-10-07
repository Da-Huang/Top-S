// Redo
double findMedianSortedArrays(int A[], int m, int B[], int n) {
  if ( m + n == 0 ) return 0;
  int kth = (m + n - 1) / 2;
  int beginA = 0, beginB = 0;
  while ( beginA < m && beginB < n && kth ) {
    int midA = beginA + min(m - 1, kth - 1) / 2;
    int midB = beginB + min(n - 1, kth - 1) / 2;
    if ( A[midA] <= B[midB] ) {
      kth -= midA - beginA + 1;
      beginA = midA + 1;

    } else {
      kth -= midB - beginB + 1;
      beginB = midB + 1;
    }
  }

  if ( beginA >= m )
    return (m + n) & 1 ? B[beginB + kth] : double(B[beginB + kth] + B[beginB + kth + 1]) / 2;
  if ( beginB >= n )
    return (m + n) & 1 ? A[beginA + kth] : double(A[beginA + kth] + A[beginA + kth + 1]) / 2;

  // kth == 0
  if ( (m + n) & 1 ) return min(A[beginA], B[beginB]);
  int r1 = min(A[beginA], B[beginB]);
  int r2 = max(A[beginA], B[beginB]);
  if ( beginA + 1 < m ) r2 = min(r2, A[beginA + 1]);
  if ( beginB + 1 < n ) r2 = min(r2, B[beginB + 1]);
  return double(r1 + r2) / 2;
}

