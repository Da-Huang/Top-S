double pow(double x, int n) {
  double res = 1;
  double y = x;
  int m = n < 0 ? - (n + 1) : n;
  for (int i = 0; i < 31; i ++) {
    if ( m & (1 << i) ) {
      res *= y;
    }
    y *= y;
  }
  if ( n < 0 ) res = 1 / res / x;
  return res;
}
