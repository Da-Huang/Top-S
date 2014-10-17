// Redo
vector<int> searchRange(int A[], int n, int target) {
  if ( n == 0 ) return {-1, -1};
  int first = 0, last = n - 1;
  while ( first < last ) {
    int mid = (first + last) / 2;
    if ( A[mid] < target ) first = mid + 1;
    else last = mid - 1;
  }
  int r1 = A[first] >= target ? first : first + 1;

  if ( r1 >= n || A[r1] != target ) return {-1, -1};
  first = r1, last = n - 1;
  while ( first < last ) {
    int mid = (first + last) / 2;
    if ( A[mid] <= target ) first = mid + 1;
    else last = mid - 1;
  }
  int r2 = A[first] <= target ? first : first - 1;

  return {r1, r2};
}
