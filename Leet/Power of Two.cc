bool isPowerOfTwo(int n) {
  if (n <= 0) return false;
  return ((n - 1) & n) == 0;
}
