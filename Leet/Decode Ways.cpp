// Redo
int numDecodings(string s) {
  const int N = s.length();
  if ( N == 0 ) return 0;
  int res[N + 1];
  memset(res, 0, sizeof(res));
  res[0] = 1;
  for (int i = 0; i < N; i ++) {
    if ( s[i] != '0' ) res[i + 1] += res[i];

    if ( s[i] == '1' && i + 1 < N ) res[i + 2] += res[i];
    if ( s[i] == '2' && i + 1 < N && s[i + 1] <= '6' ) res[i + 2] += res[i]; 
  }
  return res[N];
}

