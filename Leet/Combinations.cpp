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


// #redo
// #version2
void __combine(int n, int k, vector<int> &v, vector<vector<int>> &ans) {
  if (k == 0) {
    ans.push_back(v);
    return;
  }

  int start = v.empty() ? 1 : v.back() + 1;
  for (int i = start; i + k - 1 <= n; ++ i) {
    v.push_back(i);
    __combine(n, k - 1, v, ans);
    v.pop_back();
  }
}

vector<vector<int>> combine(int n, int k) {
  vector<vector<int>> ans;
  vector<int> v;
  __combine(n, k, v, ans);
  return ans;
}
