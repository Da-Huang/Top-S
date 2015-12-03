int nthSuperUglyNumber(int n, vector<int>& primes) {
  vector<int> ans = {1};
  int idxs[primes.size()];
  memset(idxs, 0, sizeof(idxs));
  for (int i = 1; i < n; ++i) {
    int min_value = INT_MAX;
    for (int j = 0; j < (int)primes.size(); ++j) {
      while (ans[idxs[j]] <= ans.back() / primes[j]) ++idxs[j];
      min_value = min(min_value, ans[idxs[j]] * primes[j]);
    }
    ans.push_back(min_value);
  }
  return ans.back();
}
