// #redo
string longestPalindrome(string s) {
  string str = "#";
  for (char c : s) {
    str.push_back(c);
    str.push_back('#');
  }
  const int N = str.size();
  int rads[N];
  rads[0] = 0;
  int i = 0, j = 1;
  while (j < N) {
    if (i + rads[i] < j || i + rads[i] == j + rads[2*i-j]) {
      int k = i + rads[i] + 1;
      i = j;
      while (k < N && 2*i-k >= 0 && str[k] == str[2*i-k]) ++ k;
      rads[i] = k - i - 1;

    } else {
      rads[j] = min(rads[2*i-j], i + rads[i] - j);
    }
    ++ j;
  }
  i = distance(rads, max_element(rads, rads + N));
  string ans;
  for (int j = i - rads[i]; j <= i + rads[i]; ++ j) {
    if (str[j] != '#') ans.push_back(str[j]);
  }
  return ans;
}
