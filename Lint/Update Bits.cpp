int updateBits(int n, int m, int i, int j) {
  const int WINDOW =
      j - i + 1 >= 32 ? 0xFFFFFFFF : ~(0xFFFFFFFF << (j - i + 1));
  return (n & ~(WINDOW << i)) | (m << i);
}
