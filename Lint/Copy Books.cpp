// TODO: use O(n^2) with QI
// #redo
int copyBooks(vector<int> &pages, int k) {
  const int N = pages.size();
  if (N == 0) return 0;
  if (k == 0) return INT_MAX;

  int ans[N][k];
  for (int j = 0; j < k; ++j) ans[0][j] = pages[0];
  for (int i = 1; i < N; ++i) ans[i][0] = pages[i] + ans[i - 1][0];
  for (int i = 1; i < N; ++i) {
    for (int j = 1; j < k; ++j) {
      int val = INT_MAX;
      int sum = 0;
      for (int l = i; l > 0; --l) {
        sum += pages[l];
        val = min(val, max(ans[l - 1][j - 1], sum));
      }
      ans[i][j] = val;
    }
  }
  return ans[N - 1][k - 1];
}

// #version2
bool __copyBooks(vector<int> &pages, int k, int ans) {
  int sum = 0;
  for (int i = 0; i < (int)pages.size(); ++i) {
    sum += pages[i];
    if (sum > ans) {
      sum = pages[i];
      if (sum > ans) return false;
      if (--k < 0) return false;
    }
  }
  return k > 0 || sum == 0;
}

int copyBooks(vector<int> &pages, int k) {
  int first = 0, last = INT_MAX;
  while (first < last) {
    int mid = first + (last - first) / 2;
    if (__copyBooks(pages, k, mid))
      last = mid;
    else
      first = mid + 1;
  }
  return first;
}
