vector<vector<int>> combinationSumInner(vector<int> &candidates, int target, int start=0) {
  vector<vector<int>> res;
  const int N = candidates.size();
  if ( start == N ) {
    if ( target == 0 ) {
      res.push_back(vector<int>());
    }
    return res;
  }

  for (int i = 0; i * candidates[start] <= target; i ++) {
    vector<vector<int>> subRes = combinationSumInner(candidates, target - i * candidates[start], start + 1);
    for (auto &item : subRes) {
      item.insert(item.begin(), i, candidates[start]);
      res.push_back(item);
    }
  }
  return res;
}

vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
  sort(candidates.begin(), candidates.end());
  return combinationSumInner(candidates, target);
}
