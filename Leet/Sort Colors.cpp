void sortColors(int A[], int n) {
  int b1, b2;
  b1 = b2 = 0;
  int i = 0;
  while ( i < n ) {
    if ( A[i] == 1 ) {
      swap(A[b2], A[i]);
      b2 ++;

    } else if ( A[i] == 0 ) {
      if ( b1 == b2 ) {
        swap(A[b2], A[i]);
        b2 ++; b1 ++;

      } else {
        swap(A[b1], A[i]);
        b1 ++;
        swap(A[b2], A[i]);
        b2 ++;
      }
    }
    i ++;
  }
}

