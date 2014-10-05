int __find(int A[], int n) {
  int first = 0, last = n - 1;
  while ( first < last ) {
    const int mid = (first + last) / 2;
    if ( A[mid] > A[0] ) first = mid + 1;
    else if ( A[mid] < A[0] ) last = mid - 1;
    else {
      int i = mid - 1;
      while ( i >= first && A[i] == A[0] ) i --;
      if ( i < first ) first = mid + 1;
      else if ( A[i] > A[0] ) return i + 1;
      else last = i - 1;
    }
  }
  return first;
}

bool __search(int A[], int first, int last, int target) {
  while ( first <= last ) {
    const int mid = (first + last) / 2;
    if ( A[mid] > target ) last = mid - 1;
    else if ( A[mid] < target ) first = mid + 1;
    else return true;
  }
  return false;
}

bool search(int A[], int n, int target) {
  if ( n == 0 ) return false;
  int bound = __find(A, n);
  if ( bound >= n ) return __search(A, 0, n - 1, target);
  bool b1 = __search(A, 0, bound - 1, target);
  bool b2 = __search(A, bound + 1, n - 1, target);
  bool b3 = A[bound] == target;
  return b1 | b2 | b3;
}

