int maxProfit(vector<int> &prices) {
  const int N = prices.size();
  if ( N < 2 ) return 0;
  int res = 0;
  int minPrice = prices[0];
  for (int i = 1; i < N; i ++) {
    minPrice = min(minPrice, prices[i]);
    res = max(res, prices[i] - minPrice);
  }
  return res;
}


// #version2
int maxProfit(vector<int>& prices) {
  int hold = INT_MIN, sell = 0;
  for (int price : prices) {
    hold = max(hold, -price);
    sell = max(sell, hold + price);
  }
  return sell;
}
