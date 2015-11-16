int firstBadVersion(int n) {
  int first = 1, last = n;
  while (first < last) {
    int mid = first + (last - first) / 2;
    if (isBadVersion(mid))
      last = mid;
    else
      first = mid + 1;
  }
  return first;
}
