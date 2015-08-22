// #redo
vector<int> numbersByRecursion(int n) {
  if (n == 0) return {};
  vector<int> ans(9);
  for (int i = 0; i < 9; ++i) ans[i] = i + 1;
  if (n == 1) return ans;
  
  ans = numbersByRecursion(n-1);
  int ans_size = ans.size();
  
  int base = 1;
  for (int i = 1; i < n; ++i) base *= 10;
  for (int i = 1; i <= 9; ++i) {
    ans.push_back(base * i);
    for (int j = 0; j < ans_size; ++j) {
      ans.push_back(ans[j] + base * i);
    }
  }
  return ans;
}
