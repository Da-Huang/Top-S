// #redo
bool searchMatrix(vector<vector<int>>& matrix, int target) {
  const int M = matrix.size();
  if (M == 0) return false;
  const int N = matrix[0].size();
  if (N == 0) return false;

  int first = 0, last = M;
  while (first < last) {
    int mid = first + (last - first) / 2;
    if (matrix[mid][0] < target) first = mid + 1;
    else if (matrix[mid][0] > target) last = mid;
    else return true;
  }
  if (first == 0) return false;

  int row = first - 1;
  first = 0, last = N;
  while (first < last) {
    int mid = first + (last - first) / 2;
    if (matrix[row][mid] < target) first = mid + 1;
    else if (matrix[row][mid] > target) last = mid;
    else return true;
  }
  return false;
}
