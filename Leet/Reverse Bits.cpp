uint32_t reverseBits(uint32_t n) {
  uint32_t ans = 0;
  for (int i = 0; i < 32; ++ i) {
    ans = (ans << 1) | (n & 1);
    n >>= 1;
  }
  return ans;
}

// #version2
uint32_t reverseBits(uint32_t n) {
  n = ((n & 0x55555555) << 1) | ((n >> 1) & 0x55555555);
  n = ((n & 0x33333333) << 2) | ((n >> 2) & 0x33333333);
  n = ((n & 0x0F0F0F0F) << 4) | ((n >> 4) & 0x0F0F0F0F);
  n = ((n & 0x00FF00FF) << 8) | ((n >> 8) & 0x00FF00FF);
  return ((n & 0x0000FFFF) << 16) | ((n >> 16) & 0x0000FFFF);
}
