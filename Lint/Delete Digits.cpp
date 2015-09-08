// #redo
string DeleteDigits(string A, int k) {
  string ans;
  int i = 0;
  while (i < (int)A.size()) {
    if (k <= 0 || ans.empty() || ans.back() <= A[i])
      ans.push_back(A[i++]);
    else {
      ans.pop_back();
      --k;
    }
  }
  ans.resize(max(0, (int)ans.size() - k));
  for (i = 0; i + 1 < (int)ans.size(); ++i) {
    if (ans[i] != '0') break;
  }
  ans.erase(0, i);
  if (ans.empty()) return "0";
  return ans;
}
