bool isPalindrome(int x) {
  if (x < 0) return false;
  int i = 1, j = 1;
  while (x / j / 10) j *= 10;
  while (i < j) {
    if (x / i % 10 != x / j % 10) return false;
    i *= 10;
    j /= 10;
  }
  return true;
}
