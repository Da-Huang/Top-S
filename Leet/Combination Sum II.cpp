// #redo
void __combinationSum2(vector<int>& candidates, int target, size_t begin, vector<int> &v, vector<vector<int>> &ans) {
  if (target == 0) {
    ans.push_back(v);
    return;
  }
  if (begin == candidates.size() || candidates[begin] > target) return;

  size_t end = begin + 1;
  while (end < candidates.size() && candidates[end] == candidates[begin]) ++ end;
  __combinationSum2(candidates, target, end, v, ans);
  for (size_t i = begin; i < end; ++ i) {
    v.push_back(candidates[begin]);
    __combinationSum2(candidates, target - (i-begin+1)*candidates[begin], end, v, ans);
  }
  v.erase(v.end() - end + begin, v.end());
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
  sort(candidates.begin(), candidates.end());
  vector<vector<int>> ans;
  vector<int> v;
  __combinationSum2(candidates, target, 0, v, ans);
  return ans;
}
