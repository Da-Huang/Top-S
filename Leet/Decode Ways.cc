// #redo
int numDecodings(string s) {
  const int N = s.size();
  if (N == 0) return 0;
  int ans[N+1];
  memset(ans, 0, sizeof(ans));
  ans[0] = 1;
  for (int i = 0; i < N; ++ i) {
    if (s[i] != '0') ans[i+1] += ans[i];

    if (s[i] == '1' && i + 1 < N) ans[i+2] += ans[i];
    else if (s[i] == '2' && i + 1 < N && s[i+1] <= '6') ans[i+2] += ans[i];
  }
  return ans[N];
}

// #redo
// #version2
int numDecodings(string s) {
  const int N = s.size();
  if (N == 0) return 0;
  int ans[3];
  for (int i = 0; i < N; ++ i) {
    if (s[i] != '0') ans[i%3] = i > 0 ? ans[(i-1)%3] : 1;
    else ans[i%3] = 0;

    if (i > 0) {
      if (s[i-1] == '1') ans[i%3] += i > 1 ? ans[(i-2)%3] : 1;
      else if (s[i-1] == '2' && s[i] <= '6') ans[i%3] += i > 1 ? ans[(i-2)%3] : 1;
    }
  }
  return ans[(N-1)%3];
}
