vector<vector<int>> __subsets(vector<int> &S, int begin) {
  const int N = S.size();
  vector<vector<int>> res;
  if ( begin == N ) {
    res.push_back(vector<int>());
    return res;
  }
  int end = begin + 1;
  while ( end < N && S[end] == S[begin] ) end ++;

  vector<vector<int>> subRes = __subsets(S, end);
  for (int i = 0; i <= end - begin; i ++) {
    for (auto &v : subRes) {
      res.push_back(v);
      res.back().insert(res.back().begin(), i, S[begin]);
    }
  }
  return res;
}

vector<vector<int> > subsets(vector<int> &S) {
  sort(S.begin(), S.end());
  return __subsets(S, 0);
}

