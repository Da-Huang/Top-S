int maxProfit(vector<int>& prices) {
  int hold[2], sell[2];
  fill(hold, hold + 2, INT_MIN);
  fill(sell, sell + 2, 0);
  for (int i = 0; i < (int)prices.size(); ++i) {
    int cur_hold = max(sell[(i - 2) & 1] - prices[i], hold[(i - 1) & 1]);
    int cur_sell = max(hold[(i - 1) & 1] + prices[i], sell[(i - 1) & 1]);
    hold[i & 1] = cur_hold;
    sell[i & 1] = cur_sell;
  }
  return sell[((int)prices.size() - 1) & 1];
}
