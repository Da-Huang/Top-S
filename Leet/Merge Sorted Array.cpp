void merge(int A[], int m, int B[], int n) {
  move_backward(A, A + m, A + m + n);
  int i = n, j = 0;
  int k = 0;
  while ( i < m + n && j < n ) {
    if ( A[i] <= B[j] ) A[k ++] = A[i ++];
    else A[k ++] = B[j ++];
  }
  while ( j < n ) {
    A[k ++] = B[j ++];
  }
}

