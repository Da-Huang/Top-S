string longestCommonPrefix(vector<string> &strs) {
  const int N = strs.size();
  if ( N == 0 ) return "";
  size_t len = 0;
  while ( true ) {
    if ( len >= strs[0].size() ) return strs[0].substr(0, len);
    for (int i = 1; i < N; i ++) {
      if ( len >= strs[i].size() ) return strs[0].substr(0, len);
      if ( strs[i][len] != strs[0][len] ) return strs[0].substr(0, len);
    }
    len ++;
  }
  return "";
}

