// #redo
int fastPower(int a, int b, int n) {
  if (n < 0) return 0;
  long long sum = a;
  long long ans = 1;
  int i = 0;
  while (n) {
    if (n & (1 << i)) {
      ans = (ans * sum) % b;
    }
    n &= ~(1 << i);
    sum = (sum * sum) % b;
    ++i;
  }
  return ans % b;
}
