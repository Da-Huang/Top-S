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

// #version2
int nthSuperUglyNumber(int n, vector<int>& primes) {
  int ans_idxs[primes.size()];
  memset(ans_idxs, 0, sizeof(ans_idxs));
  vector<int> ans = {1};
  vector<int> idx_heap(primes.size());
  iota(idx_heap.begin(), idx_heap.end(), 0);
  auto greater_num = [&primes, &ans_idxs, &ans](int i, int j) {
    return ans[ans_idxs[i]] * primes[i] > ans[ans_idxs[j]] * primes[j];
  };
  make_heap(idx_heap.begin(), idx_heap.end(), greater_num);
  while ((int)ans.size() < n) {
    int num = ans[ans_idxs[idx_heap[0]]] * primes[idx_heap[0]];
    if (num != ans.back()) ans.push_back(num);
    pop_heap(idx_heap.begin(), idx_heap.end(), greater_num);
    ++ans_idxs[idx_heap.back()];
    push_heap(idx_heap.begin(), idx_heap.end(), greater_num);
  }
  return ans.back();
}
