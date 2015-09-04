// #redo
int hIndex(vector<int>& citations) {
  const int N = citations.size();
  if (N == 0) return 0;
  int first = 0, last = N - 1;
  while (first < last) {
    int first1 = first + 1, last1 = last;
    while (first1 <= last1) {
      if (citations[first1] < citations[first])
        ++first1;
      else if (citations[last1] >= citations[first])
        --last1;
      else {
        swap(citations[first1], citations[last1]);
        ++first1;
        --last1;
      }
    }
    int p = first1 - 1;
    swap(citations[first], citations[p]);
    if (N - p == citations[p])
      return citations[p];
    else if (N - p > citations[p])
      first = p + 1;
    else
      last = p - 1;
  }
  return N - first <= citations[first] ? N - first : N - first - 1;
}
