int triangleCount(vector<int> &S) {
  sort(S.begin(), S.end());
  int ans = 0;
  for (size_t k = 2; k < S.size(); ++k) {
    size_t i = 0, j = k - 1;
    while (i < j) {
      if (S[i] + S[j] > S[k]) {
        ans += j - i;
        --j;
      } else ++ i;
    }
  }
  return ans;
}
