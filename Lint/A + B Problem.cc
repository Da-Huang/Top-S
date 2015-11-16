int aplusb(int a, int b) {
  while (a & b) {
    int p = a ^ b;
    int c = (a & b) << 1;
    a = p;
    b = c;
  }
  return a | b;
}
