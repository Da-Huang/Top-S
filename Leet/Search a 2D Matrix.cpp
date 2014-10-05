bool searchMatrix(vector<vector<int> > &matrix, int target) {
  const int M = matrix.size();
  if ( M == 0 ) return false;
  const int N = matrix[0].size();
  if ( N == 0 ) return false;
  int first = 0;
  int last = M - 1;
  while ( first < last ) {
    int mid = (first + last) / 2;
    if ( matrix[mid][0] > target ) last = mid - 1;
    else if ( matrix[mid][0] < target ) first = mid + 1;
    else return true;
  }
  int ROW;
  if ( matrix[first][0] <= target ) ROW = first;
  else ROW = first - 1;
  if ( ROW < 0 ) return false;
  first = 0, last = N - 1;
  while ( first <= last ) {
    int mid = (first + last) / 2;
    if ( matrix[ROW][mid] > target ) last = mid - 1;
    else if ( matrix[ROW][mid] < target ) first = mid + 1;
    else return true;
  }
  return false;
}

