int bitSwapRequired(int a, int b) {
  int x = a ^ b;
  x = (x & 0x55555555) + (((unsigned int)x >> 1) & 0x55555555);
  x = (x & 0x33333333) + (((unsigned int)x >> 2) & 0x33333333);
  x = (x & 0x0F0F0F0F) + (((unsigned int)x >> 4) & 0x0F0F0F0F);
  x = (x & 0x00FF00FF) + (((unsigned int)x >> 8) & 0x00FF00FF);
  x = (x & 0x0000FFFF) + (((unsigned int)x >> 16) & 0x0000FFFF);
  return x;
}
