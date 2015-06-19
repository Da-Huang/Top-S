// #redo
string shortestPalindrome(string s) {
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
    if (j > i + rads[i] || j + rads[2*i-j] == i + rads[i]) {
      int k = i + rads[i] + 1;
      i = j;
      while (k < N && 2*i-k >= 0 && str[k] == str[2*i-k]) ++ k;
      rads[i] = k - i - 1;
      j = i + 1;

    } else {
      rads[j] = min(rads[2*i-j], i+rads[i]-j);
      ++ j;
    }
  }

  i = N - 1;
  while (i >= 0 && i - rads[i] != 0) -- i;
  string strc = str.substr(i + rads[i] + 1);
  reverse(strc.begin(), strc.end());
  str = strc + str;
  string ans;
  for (char c : str) {
    if (c != '#') ans.push_back(c);
  }
  return ans;
}
