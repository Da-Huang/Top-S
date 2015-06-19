// #redo
// NOTE: slower but easier
int maxProfit(int k, vector<int>& prices) {
  const int N = prices.size();
  if (k >= N / 2) {
    int ans = 0;
    for (int i = 1; i < N; ++ i) {
      ans += max(prices[i] - prices[i-1], 0);
    }
    return ans;
  }
  if (k == 0) return 0;
  int hold[k], sell[k];
  fill(hold, hold + k, INT_MIN);
  fill(sell, sell + k, 0);
  for (int price : prices) {
    hold[0] = max(hold[0], -price);
    sell[0] = max(sell[0], hold[0] + price);
    for (int i = 1; i < k; ++ i) {
      hold[i] = max(hold[i], sell[i-1] - price);
      sell[i] = max(sell[i], hold[i] + price);
    }
  }
  return sell[k - 1];
}


// #version2
int maxProfit(int k, vector<int>& prices) {
  const int N = prices.size();
  vector<int> profits;
  stack<pair<int, int>> vps;
  int v = 0;
  while (v < N) {
    while (v + 1 < N && prices[v+1] <= prices[v]) ++ v;
    int p = v;
    while (p + 1 < N && prices[p+1] >= prices[p]) ++ p;

    while (!vps.empty() && prices[v] <= prices[vps.top().first]) {
      profits.push_back(prices[vps.top().second] - prices[vps.top().first]);
      vps.pop();
    }
    while (!vps.empty() && prices[p] >= prices[vps.top().second]) {
      profits.push_back(prices[vps.top().second] - prices[v]);
      v = vps.top().first;
      vps.pop();
    }
    vps.push(make_pair(v, p));
    v = p + 1;
  }
  while (!vps.empty()) {
    profits.push_back(prices[vps.top().second] - prices[vps.top().first]);
    vps.pop();
  }
  k = min(k, (int) profits.size());
  nth_element(profits.begin(), profits.begin() + k, profits.end(), greater<int>());
  int ans = 0;
  for (int i = 0; i < k; ++ i) ans += profits[i];
  return ans;
}
