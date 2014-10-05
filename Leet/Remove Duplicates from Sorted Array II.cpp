int removeDuplicates(int A[], int n) {
  int i = 0;
  int begin = 0;
  while ( begin < n ) {
    int end = begin + 1;
    while ( end < n && A[end] == A[begin] ) end ++;
    for (int j = 0; j < min(2, end - begin); j ++) {
      A[i ++] = A[begin + j];
    }
    begin = end;
  }
  return i;
}

