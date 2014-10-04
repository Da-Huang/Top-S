vector<vector<int>> __combinationSum2(vector<int> &num, int target, int begin=0) {
  vector<vector<int>> res;
  const int N = num.size();
  if ( begin == N ) {
    if ( target == 0 ) res.push_back(vector<int>());
    return res;
  }
  int end = begin + 1;
  while ( end < N && num[end] == num[begin] ) end ++;
  for (int i = 0; i <= end - begin && num[begin] * i <= target; i ++) {
    vector<vector<int>> subRes = __combinationSum2(num, target - num[begin] * i, end);
    for (auto &v : subRes) {
      v.insert(v.begin(), i, num[begin]);
      res.push_back(v);
    }
  }
  return res;
}

vector<vector<int> > combinationSum2(vector<int> &num, int target) {
  sort(num.begin(), num.end());
  return __combinationSum2(num, target);
}

