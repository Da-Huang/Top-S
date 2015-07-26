bool searchMatrix(vector<vector<int>>& matrix, int target) {
  const int M = matrix.size();
  if (M == 0) return false;
  const int N = matrix[0].size();
  if (N == 0) return false;
  int i = 0, j = N - 1;
  while (i < M && j >= 0) {
    if (matrix[i][j] > target) --j;
    else if (matrix[i][j] < target) ++i;
    else return true;
  } 
  return false;
}
