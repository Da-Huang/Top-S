int climbStairs(int n) {
  if ( n <= 1 ) return 1;
  int res[3];
  res[0] = 1;
  res[1] = 1;
  for (int i = 2; i <= n; i ++) {
    res[i%3] = res[(i - 2)%3] + res[(i - 1)%3];
  }
  return res[n%3];
}

