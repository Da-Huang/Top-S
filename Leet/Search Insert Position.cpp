int searchInsert(int A[], int n, int target) {
  if ( n == 0 ) return 0;
  int first = 0, last = n - 1;
  while ( first < last ) {
    const int mid = (first + last) / 2;
    if ( A[mid] >= target ) last = mid - 1;
    else first = mid + 1;
  }
  if ( A[first] >= target ) return first;
  else return first + 1;
}

