// #redo
int hIndex(vector<int>& citations) {
  const int N = citations.size();
  int first = 0, last = N;
  while (first < last) {
    int mid = first + (last - first) / 2;
    if (citations[mid] > N - mid)
      last = mid;
    else if (citations[mid] < N - mid)
      first = mid + 1;
    else
      return N - mid;
  }
  return N - first;
}
