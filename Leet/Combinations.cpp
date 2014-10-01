vector<vector<int>> combineInner(int n, int k, int start=1) {
  vector<vector<int>> res;
  if ( k == 0 ) {
    res.push_back(vector<int>());
    return res;
  }
  for (int i = start; i <= n - k + 1; i ++) {
    vector<vector<int>> subRes = combineInner(n, k - 1, i + 1);
    for (auto &item : subRes) {
      item.insert(item.begin(), i);
      res.push_back(item);
    }
  }
  return res;
}

vector<vector<int> > combine(int n, int k) {
  return combineInner(n, k);
}
