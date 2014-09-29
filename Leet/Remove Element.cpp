int removeElement(int A[], int n, int elem) {
  int len = 0, i = 0;
  while ( i < n ) {
    if ( A[i] != elem )
      A[len ++] = A[i];
    i ++;
  }
  return len;
}

