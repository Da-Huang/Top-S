string getPermutation(int n, int k) {
  int NUMS[n + 1];
  NUMS[0] = 1;
  for (int i = 1; i <= n; i ++)
    NUMS[i] = NUMS[i - 1] * i;
  // NUMS[n] == n!
  k = (k - 1) % NUMS[n] + 1;

  string res;
  vector<bool> selected(n + 1, false);
  for (int i = n - 1; i >= 0; i --) {
    int j = 1;
    while ( j < n ) {
      if ( k <= NUMS[i] * j ) {
        break;
      }
      j ++;
    }
    k -= NUMS[i] * (j - 1);
    int count = 0;
    for (int t = 1; t <= n; t ++) {
      if ( !selected[t] ) {
        count ++;
        if ( count == j ) {
          selected[t] = true;
          res += to_string(t);
          break;
        }
      }
    }
  }
  return res;
}
