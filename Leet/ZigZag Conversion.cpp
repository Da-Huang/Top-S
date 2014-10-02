string convert(string s, int nRows) {
  if ( nRows == 1 ) return s;
  string res;
  const int N = s.length();
  for (int k = 0; k < N; k += 2*nRows-2) res.push_back(s[k]);
  for (int i = 1; i < nRows - 1; i ++) {
    int t = 1;
    for (int k = i; k < N; k += 2*nRows-2) {
      res.push_back(s[k]);
      int j = (2*nRows-2)*t-k;
      t += 2;
      if ( j < N ) res.push_back(s[j]);
      else break;
    }
  }
  for (int k = nRows-1; k < N; k += 2*nRows-2) res.push_back(s[k]);
  return res;
}
