// #TODO: count while bucket sorting.
// #redo
void sortColors2(vector<int> &colors, int k) {
  int i = 0;
  while (i < (int)colors.size()) {
    if (colors[i] != colors[colors[i] - 1]) {
      swap(colors[i], colors[colors[i] - 1]);
    } else {
      ++i;
    }
  }
  for (int i = 0; i < k; ++i)
    if (colors[i] == i + 1) colors[i] = k + 1;
  for (int i = 0; i < (int)colors.size(); ++i) {
    if (colors[i] <= k)
      ++colors[colors[i] - 1];
    else
      colors[i] = 0;
  }
  i = k - 1;
  int j = (int)colors.size() - 1;
  while (i >= 0) {
    if (colors[i] > k) {
      int start = j - colors[i] + k + 1;
      for (; j >= start; --j) colors[j] = i + 1;
    }
    --i;
  }
}
