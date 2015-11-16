int strStr(string haystack, string needle) {
  const int M = needle.size();
  if (M == 0) return 0;
  int next[M];
  next[0] = -1;
  int i = 1, j = -1;
  while (i < M) {
    if (j < 0 || needle[i-1] == needle[j]) next[i ++] = ++ j;
    else j = next[j];
  }

  const int N = haystack.size();
  i = 0, j = 0;
  while (i < N) {
    if (j < 0) {
      j = 0;
      ++ i;
    } else if (haystack[i] == needle[j]) {
      ++ i;
      ++ j;
      if (j == M) return i - M;
    } else {
      j = next[j];
    }
  }
  return -1;
}
