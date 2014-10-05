pair<int, int> __maxInc(vector<int> &prices, int first, int last) {
  int r1 = first, r2 = first;
  int minIndex = first;
  for (int i = first + 1; i <= last; i ++) {
    if ( prices[i] < prices[minIndex] ) minIndex = i;
    else if ( prices[i] - prices[minIndex] > prices[r2] - prices[r1] ) {
      r1 = minIndex;
      r2 = i;
    }
  }
  return make_pair(r1, r2);
}

int __maxDec(vector<int> &prices, int first, int last) {
  int res = 0;
  int maxVal = 0;
  for (int i = first + 1; i <= last; i ++) {
    maxVal = max(maxVal, prices[i]);
    res = max(res, maxVal - prices[i]);
  }
  return res;
}

int maxProfit(vector<int> &prices) {
  const int N = prices.size();
  auto p0 = __maxInc(prices, 0, N - 1);
  auto p1 = __maxInc(prices, 0, p0.first - 1);
  auto p2 = __maxInc(prices, p0.second + 1, N - 1);
  int v0 = p0.first < p0.second ? prices[p0.second] - prices[p0.first] : 0;
  int v1 = p1.first < p1.second ? prices[p1.second] - prices[p1.first] : 0;
  int v2 = p2.first < p2.second ? prices[p2.second] - prices[p2.first] : 0;
  int v4 = __maxDec(prices, p0.first, p0.second);
  return max({v0 + v1, v0 + v2, v0 + v4});
}

