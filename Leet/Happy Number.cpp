bool isHappy(int n) {
  if (n <= 0) return false;
  unordered_set<int> SET;
  SET.insert(n);
  while (n > 1) {
    int m = 0;
    while (n) {
      int p = n % 10;
      m += p * p;
      n /= 10;
    }
    n = m;
    if (SET.find(n) == SET.end()) SET.insert(n);
    else return false;
  }
  return true;
}
