vector<vector<int>> generate(int numRows) {
  vector<vector<int>> ans;
  if (numRows == 0) return ans;
  for (int i = 0; i < numRows; ++ i) {
    ans.push_back(vector<int>(i + 1, 1));
    for (int j = 1; j < i; ++ j) ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
  }
  return ans;
}
