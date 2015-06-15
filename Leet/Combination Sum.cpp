void __combinationSum(vector<int> &candidates, int target, int begin, vector<int> &v, vector<vector<int>> &ans) {
  if (target == 0) {
    ans.push_back(v);
    return;
  }
  if (begin == candidates.size()) return;

  __combinationSum(candidates, target, begin+1, v, ans);
  int sum = candidates[begin];
  int size = v.size();
  while (sum <= target) {
    v.push_back(candidates[begin]);
    __combinationSum(candidates, target-sum, begin+1, v, ans);
    sum += candidates[begin];
  }
  v.resize(size);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
  vector<vector<int>> ans;
  vector<int> v;
  sort(candidates.begin(), candidates.end());
  __combinationSum(candidates, target, 0, v, ans);
  return ans;
}
