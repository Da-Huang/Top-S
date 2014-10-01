int findBound(int A[], int first, int last) {
  while ( first < last ) {
    const int mid = (first + last) / 2;
    if ( A[mid] >= A[0] ) first = mid + 1;
    else last = mid - 1;
  }
  if ( A[first] < A[0] ) return first;
  else return first + 1;
}

int binarySearch(int A[], int first, int last, int target) {
  while ( first <= last ) {
    const int mid = (first + last) / 2;
    if ( A[mid] > target ) last = mid - 1;
    else if ( A[mid] < target ) first = mid + 1;
    else return mid;
  }
  return -1;
}

int search(int A[], int n, int target) {
  int bound = findBound(A, 0, n - 1);
  return max(binarySearch(A, 0, bound - 1, target), binarySearch(A, bound, n - 1, target));
}
