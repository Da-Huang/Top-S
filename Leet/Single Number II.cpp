int singleNumber(int A[], int n) {
  int res = 0;
  for (int i = 0; i < 32; i ++) {
    int sum = 0;
    for (int j = 0; j < n; j ++) {
      sum += (A[j] >> i) & 1;
    }
    if ( sum % 3 ) {
      res |= 1 << i;
    }
  }
  return res;
}

