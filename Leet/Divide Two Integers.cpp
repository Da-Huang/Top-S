// #redo
int divide(int dividend, int divisor) {
  if ( dividend == INT_MIN && divisor == -1 ) return INT_MAX;
  if ( divisor == 0 ) return dividend > 0 ? INT_MAX : dividend < 0 ? INT_MIN : 0;
  if ( dividend == 0 ) return 0;

  bool isNegative = (dividend < 0) ^ (divisor < 0);
  if ( dividend > 0 ) dividend = -dividend;
  if ( divisor > 0 ) divisor = -divisor;

  int BOUND = 0;
  while ( BOUND <= 31 ) {
    if ( (divisor << (BOUND + 1)) >= 0 || dividend > (divisor << (BOUND + 1)) ) break;
    BOUND ++;
  }
  int res = 0;
  for (int i = BOUND; i >= 0; i --) {
    if ( dividend <= (divisor << i) ) {
      dividend -= (divisor << i);
      res += 1 << i;
    } 
  }
  return isNegative ? -res : res;
}
