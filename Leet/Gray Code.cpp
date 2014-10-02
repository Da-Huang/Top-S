vector<int> grayCode(int n) {
  vector<int> res;
  res.push_back(0);
  int N = 1;
  for (int i = 0; i < n; i ++) {
    int highestBit = 1 << i;
    for (int i = N - 1; i >= 0; i --) {
      res.push_back(res[i] | highestBit);
    }
    N <<= 1;
  }
  return res;
}
