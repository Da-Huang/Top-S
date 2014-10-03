double findMedianSortedArrays(int A[], int m, int B[], int n) {
  int beginA = 0, beginB = 0;
  int kth = (m + n - 1) / 2;
  while ( beginA < m && beginB < n && kth > 0 ) {
    int dA = min(beginA + (kth - 1) / 2, m - 1);
    int dB = min(beginB + (kth - 1) / 2, n - 1);
    if ( A[dA] <= B[dB] ) {
      kth -= dA + 1 - beginA;
      beginA = dA + 1;
    } else {
      kth -= dB + 1 - beginB;
      beginB = dB + 1;
    }
  }
  if ( beginA == m ) {
    if ( (m + n) & 1 ) return B[beginB + kth];
    else return double(B[beginB + kth] + B[beginB + kth + 1]) / 2;
  }
  if ( beginB == n ) {
    if ( (m + n) & 1 ) return A[beginA + kth];
    else return double(A[beginA + kth] + A[beginA + kth + 1]) / 2;
  }
  // kth == 0
  int first = min(A[beginA], B[beginB]);
  if ( (m + n) & 1 ) return first;
  int secondA = beginA + 1 < m ? A[beginA + 1] : INT_MAX;
  int secondB = beginB + 1 < n ? B[beginB + 1] : INT_MAX;
  int second = min({secondA, secondB, max(A[beginA], B[beginB])});
  return double(first + second) / 2;
}

