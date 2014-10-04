int reverse(int x) {
  if ( x == 0 ) return 0;
  bool isNegative = x < 0;
  if ( x > 0 ) x = -x;
  int res = 0;
  while ( x ) {
    int d = x % 10;
    if ( res < (INT_MIN - d) / 10 ) {
      return isNegative ? INT_MIN : INT_MAX;
    }
    res = res * 10 + d;
    x = x / 10;
  }
  if ( isNegative ) return res;
  else if ( res == INT_MIN ) return INT_MAX;
  else return -res;
}

