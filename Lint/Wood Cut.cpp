// #redo
bool __woodCut(const vector<int> &L, int k, int ans) {
  if (k == 0 || ans == 0) return true;
  int count = 0;
  for (int l : L) {
    count += l / ans;
    if (count >= k) return true;
  }
  return false;
}

int woodCut(vector<int> L, int k) {
  int first = 1, last = INT_MAX;  // TODO: use max value
  while (first < last) {
    int mid = first + (last - first) / 2;
    if (__woodCut(L, k, mid))
      first = mid + 1;
    else
      last = mid;
  }
  return first - 1;
}
