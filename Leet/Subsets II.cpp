vector<vector<int>> __subsetsWithDup(vector<int> &S, int start=0) {
  vector<vector<int>> res;
  const int N = S.size();
  if ( start == N ) {
    res.push_back(vector<int>());
    return res;
  }
  int end = start + 1;
  while ( end < N && S[end] == S[start] ) end ++;
  vector<vector<int>> subRes = __subsetsWithDup(S, end);
  for (int i = 0; i <= end - start; i ++) {
    for (auto &item : subRes) {
      res.push_back(item);
      res.rbegin()->insert(res.rbegin()->begin(), i, S[start]);
    }
  }
  return res;
}

vector<vector<int> > subsetsWithDup(vector<int> &S) {
  sort(S.begin(), S.end());
  return __subsetsWithDup(S);
}
