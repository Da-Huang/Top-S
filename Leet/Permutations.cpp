vector<vector<int>> permute(vector<int> &num, vector<bool> &selected, int len=0) {
  vector<vector<int>> res;
  const int N = num.size();
  if ( len >= N ) {
    res.push_back(vector<int>());
    return res;
  }
  for (int i = 0; i < N; i ++) {
    if ( !selected[i] ) {
      selected[i] = true;
      vector<vector<int>> subRes = permute(num, selected, len + 1);
      for (auto &item : subRes) {
        item.insert(item.begin(), num[i]);
        res.push_back(item);
      }
      selected[i] = false;
    }
  }
  return res;
}

vector<vector<int> > permute(vector<int> &num) {
  vector<bool> selected(num.size(), false);
  return permute(num, selected);
}
