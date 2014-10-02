vector<vector<int> > generate(int numRows) {
  vector<vector<int>> res;
  if ( numRows == 0 ) return res;
  res.push_back(vector<int>(1, 1));
  for (int i = 1; i < numRows; i ++) {
    res.push_back(vector<int>(i + 1));
    res[i][0] = 1;
    res[i][i] = 1;
    for (int j = 1; j < i; j ++) {
      res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
    }
  }
  return res;
}
