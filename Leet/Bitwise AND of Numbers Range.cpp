// #redo
int rangeBitwiseAnd(int m, int n) {
  int k = m ^ n;
  int mask = -1;
  while (k) {
    k >>= 1;
    mask <<= 1;
  }
  return mask & m;
}
