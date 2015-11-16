// #redo
string addBinary(string a, string b) {
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  string ans;
  int c = 0;
  size_t i = 0, j = 0;
  while (i < a.size() || j < b.size() || c) {
    int p = c;
    if (i < a.size()) p += a[i++] - '0';
    if (j < b.size()) p += b[j++] - '0';
    ans.push_back((p & 1) + '0');
    c = p >> 1;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}
