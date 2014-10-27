// Redo
bool isMatch(const char *s, const char *p) {
  const int N = strlen(s);
  if ( *p == 0 ) return N == 0;
  auto equalC = [] (char c1, char c2) {
    return c1 == c2 || c1 == '?' || c2 == '?';
  };

  int i = 0;
  int begin = 0;
  while ( p[begin] ) {
    if ( p[begin] == '*' ) {
      begin ++;
      continue;
    }
    int end = begin + 1;
    while ( p[end] && p[end] != '*' ) end ++;
    int index = distance(s, search(s + i, s + N, p + begin, p + end, equalC));
    if ( index == N ) return false;
    if ( begin == 0 ) {
      if ( index != 0 ) return false;
      if ( p[end] == 0 ) return index + end - begin == N;
    } else {
      if ( p[end] == 0 ) {
        int index = distance(s, find_end(s + i, s + N, p + begin, p + end, equalC));
        return index + end - begin == N;
      }
    }
    i = index + end - begin;
    begin = end;
  }
  return true;
}

