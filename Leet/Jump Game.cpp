bool canJump(int A[], int n) {
  if ( n == 0 ) return true;
  int res[n];
  res[0] = true;
  int end = 1;
  for (int i = 0; i < n; i ++) {
    if ( i >= end ) return false;
    while ( end < n && i + A[i] >= end ) res[end ++] = true;
  }
  return true;
}

