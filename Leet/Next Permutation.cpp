void nextPermutation(vector<int> &num) {
  const int N = num.size();
  if ( N <= 1 ) return;
  int i = N - 2;
  while ( i >= 0 && num[i] >= num[i + 1] ) i --;
  // i + 1, i + 2, ... , N - 1 is decreasing.
  reverse(num.begin() + i + 1, num.end());
  if ( i >= 0 ) {
    int target = -1;
    for (int k = i + 1; k < N; k ++) {
      if ( num[k] > num[i] && (target < 0 || num[k] < num[target]) ) {
        target = k;
      }
    }
    swap(num[i], num[target]);
  }
}
