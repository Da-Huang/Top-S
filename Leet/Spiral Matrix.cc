// #redo
vector<int> spiralOrder(vector<vector<int>>& matrix) {
  vector<int> ans;
  const int M = matrix.size();
  if (M == 0) return ans;
  const int N = matrix[0].size();
  if (N == 0) return ans;

  for (int row = 0; row <= M-1-row && row <= N-1-row; ++ row) {
    int i = row, j;
    for (j = row; j < N - 1 - row; ++ j) ans.push_back(matrix[i][j]);
    for (; i <= M - 1 - row; ++ i) ans.push_back(matrix[i][j]);
    if (row == N - 1 - row || row == M - 1 - row) break;
    i = M - 1 - row;
    for (j = N - 1 - row - 1; j > row; -- j) ans.push_back(matrix[i][j]);
    for (; i > row; -- i) ans.push_back(matrix[i][j]);
  }
  return ans;
}
