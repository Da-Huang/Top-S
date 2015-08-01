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

// #redo
// #version2
int countDigitOne(int n) {
  int ans = 0;
  int base = 1;
  while (n / base) {
    ans += n / base / 10 * base;
    
    int p = n / base % 10;
    if (p == 1) ans += n % base + 1;
    else if (p > 1) ans += base;
    
    if (n / 10 < base) break;
    base *= 10;
  }
  return ans;
}
