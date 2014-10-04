// Redo
bool isMatch(const char *s, const char *p) {
  const int N = strlen(s);
  const int M = strlen(p);
  int i = 0, j = 0;
  auto equalC = [] (char c1, char c2) {
    return c1 == c2 || c1 == '?' || c2 == '?';
  };
  while ( s[i] && p[i] && p[i] != '*' ) {
    if ( !equalC(s[i], p[j]) ) return false;
    i ++; j ++;
  }
  if ( p[j] == 0 && s[i] == 0 ) return true;
  if ( p[j] == 0 ) return false;

  // p[j] == '*'
  while ( p[j] == '*' ) j ++;
  if ( p[j] == 0 ) return true;
  if ( s[i] == 0 ) return false;

  while ( p[j] ) {
    int endJ = j + 1;
    while ( p[endJ] && p[endJ] != '*' ) endJ ++;
    int endJ2 = endJ;
    while ( p[endJ2] == '*' ) endJ2 ++;

    if ( p[endJ] ) {
      auto it = search(s + i, s + N, p + j, p + endJ, equalC);
      if ( it == s + N ) return false;
      i = distance(s, it) + endJ - j;
      j = endJ2;
      if ( p[j] == 0 ) return true;

    } else {
      auto it = find_end(s + i, s + N, p + j, p + endJ, equalC);
      if ( it == s + N ) return false;
      i = distance(s, it) + endJ - j;
      return i == N;
    }
  }
  return false;
}

