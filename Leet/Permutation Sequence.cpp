// #redo
string getPermutation(int n, int k) {
  int T = 1;
  for (int i = 1; i <= n; ++ i) T *= i;
  k = (k - 1) % T;
  vector<bool> visited(n, false);
  string ans;
  for (int i = n - 1; i >= 0; -- i) {
    T /= i + 1;
    int c = k / T;
    for (int j = 0; j < n; ++ j) {
      if (!visited[j]) {
        if (c == 0) {
          ans.push_back(j + '1');
          visited[j] = true;
          break;
        }
        -- c;
      }
    }
    k %= T;
  }
  return ans;
}
