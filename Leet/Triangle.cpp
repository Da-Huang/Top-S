int minimumTotal(vector<vector<int> > &triangle) {
  const int N = triangle.size();
  if ( N == 0 ) return 0;
  int res[N];
  res[0] = triangle[0][0];
  for (int i = 1; i < N; i ++) {
    res[i] = triangle[i][i] + res[i - 1];
    for (int j = i - 1; j > 0; j --) {
      res[j] = min(res[j], res[j - 1]) + triangle[i][j];
    }
    res[0] += triangle[i][0];
  }
  return *min_element(res, res + N);
}

