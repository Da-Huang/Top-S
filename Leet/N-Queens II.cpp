int __solve(int n, 
    unsigned long long attackL=0, unsigned long long attackR=0, unsigned long long attackV=0, int begin=0) {
  if ( begin == n ) return 1;
  int res = 0;
  unsigned long long attack = attackL | attackR | attackV;
  for (int i = 0; i < n; i ++) {
    if ( (attack & (1 << i)) == 0 ) {
      unsigned long long nextAttackL = attackL;
      unsigned long long nextAttackR = attackR;
      unsigned long long nextAttackV = attackV;
      nextAttackL |= 1 << i;
      nextAttackL <<= 1;
      nextAttackR |= 1 << i;
      nextAttackR >>= 1;
      nextAttackV |= 1 << i;
      res += __solve(n, nextAttackL, nextAttackR, nextAttackV, begin + 1);
    }
  }
  return res;
}

int totalNQueens(int n) {
  return __solve(n);
}

