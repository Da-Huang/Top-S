int countDigitOne(int n) {
  if (n < 1) return 0;
  int base = 1;
  int k = 0;
  while (n / base >= 10) {
    base *= 10;
    ++k;
  }
  int ans = 0;
  while (base) {
    int p = n / base;
    int q = n % base;
    ans += p * base / 10 * k;
    if (p > 1) ans += base;
    else if (p == 1) ans += q + 1;
    --k;
    base /= 10;
    n = q;
  }
  return ans;
}
