// #redo
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


// #version2
bool isMatch(string s, string p) {
  auto equalMatch = [](char a, char b) {
    return a == '?' || b == '?' || a == b;
  };
  const int NS = s.size();
  const int NP = p.size();

  int si = 0, pi = -1, pj;
  for (int i = 0; i <= NP; ++ i) {
    if (i == NP || p[i] == '*') {
      if (pi < 0) continue;
      pj = i;
      if (pi == 0) {
        if (s.size() >= pj && equal(p.begin(), p.begin()+pj, s.begin(), equalMatch)) {
          si = pj - pi;
          if (pj == NP) return si == NS;
        } else return false;
      } else if (pj == NP) {
        return find_end(s.begin()+si, s.end(), p.begin()+pi, p.end(), equalMatch)+pj-pi == s.end();
      } else {
        auto it = search(s.begin()+si, s.end(), p.begin()+pi, p.begin()+pj, equalMatch);
        if (it == s.end()) return false;
        si = distance(s.begin(), it) + pj - pi;
      }
      pi = -1;

    } else if (pi < 0) {
      pi = i;
    }
  }
  if (p.empty() && !s.empty()) return false;
  return true;
}

