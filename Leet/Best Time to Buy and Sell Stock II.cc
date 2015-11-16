int maxProfit(vector<int>& prices) {
  int ans = 0;
  for (size_t i = 1; i < prices.size(); ++ i) {
    ans += max(prices[i] - prices[i - 1], 0);
  }
  return ans;
}
