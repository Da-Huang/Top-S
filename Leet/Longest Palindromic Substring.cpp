string longestPalindrome(string s) {
  int N = s.length();
  string extend = "#";
  for (auto c : s) {
    extend.push_back(c);
    extend.push_back('#');
  }
  N = 2 * N + 1;
  int radis[N];
  radis[0] = 0;
  int i = 0;
  while ( i < N ) {
    int j = i + 1;
    while ( j < i + radis[i] ) {
      const int j2 = 2 * i - j;
      if ( i - radis[i] != j2 - radis[j2] ) {
        radis[j] = min(radis[j2], i + radis[i] - j);
        j ++;

      } else {
        int k = i + radis[i] + 1;
        while ( k < N && 2*j-k >= 0 && extend[k] == extend[2*j-k] ) k ++;
        radis[j] = k - j - 1;
        i = j;
        j = i + 1;
      }
    }
    i = j;
    j = i + 1;
    while ( j < N && 2*i-j >= 0 && extend[j] == extend[2*i-j] ) j ++;
    radis[i] = j - i - 1;
  }
  int maxIndex = distance(radis, max_element(radis, radis + N));
  string res;
  for (int i = maxIndex - radis[maxIndex]; i <= maxIndex + radis[maxIndex]; i ++) {
    if ( extend[i] != '#' ) res.push_back(extend[i]);
  }
  return res;
}

