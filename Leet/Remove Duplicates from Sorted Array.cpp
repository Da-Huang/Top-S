int removeDuplicates(int A[], int n) {
  int begin = 0, end = 0;
  while ( end < n ) {
    A[begin] = A[end];
    end ++;
    while ( end < n && A[begin] == A[end] ) end ++;
    begin ++;
  }
  return begin;
}

