string convert(string s, int numRows) {
  if (numRows == 1) return s;
  string ans;
  const int N = s.size();
  for (int k = 0; k < N; k += numRows*2-2) ans.push_back(s[k]);
  for (int i = 1; i < numRows - 1; ++ i) {
    for (int k = i; k < N; k += numRows*2-2) {
      ans.push_back(s[k]);
      int t = k + numRows*2 - 2 - 2 * i;
      if (t < N) ans.push_back(s[t]);
    }
  }
  for (int k = numRows-1; k < N; k += numRows*2-2) ans.push_back(s[k]);
  return ans;
}
