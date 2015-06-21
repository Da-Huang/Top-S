// #redo
int divide(int dividend, int divisor) {
  if (divisor == 0) return INT_MAX;
  if (dividend == INT_MIN && divisor == -1) return INT_MAX;
  if (dividend == 0) return 0;
  // if (divisor == 1) return dividend; // this line can be removed

  bool isNegative = (dividend < 0) ^ (divisor < 0);
  if (dividend > 0) dividend = -dividend;
  if (divisor > 0) divisor = -divisor;
  int ans = 0, shift = 1;
  while (shift < 32 && (divisor << shift) < 0 && dividend <= (divisor << shift)) ++ shift;
  while (-- shift >= 0) {
    if (dividend <= (divisor << shift)) {
      dividend -= divisor << shift;
      ans |= 1 << shift;
    }
  }
  return isNegative ? -ans : ans;
}
