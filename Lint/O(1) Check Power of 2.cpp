bool checkPowerOf2(int n) { return n > 0 ? (n & (n - 1)) == 0 : false; }
