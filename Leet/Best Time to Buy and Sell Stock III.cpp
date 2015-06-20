int maxProfit(vector<int>& prices) {
  int hold0 = INT_MIN, hold1 = INT_MIN;
  int sell0 = 0, sell1 = 0;
  for (int price : prices) {
    hold0 = max(hold0, -price);
    sell0 = max(sell0, hold0 + price);
    hold1 = max(hold1, sell0 - price);
    sell1 = max(sell1, hold1 + price);
  }
  return sell1;
}
