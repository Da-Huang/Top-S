// Redo
string minWindow(string S, string T) {
  const int M = T.length();
  S.push_back('#');
  const int N = S.length();
  if ( M == 0 ) return "";
  int dict[128], mapping[128];
  memset(dict, 0, sizeof(dict));
  memset(mapping, 0, sizeof(mapping));
  for (auto c : T) dict[c] ++;

  int resBegin = 0, resEnd = 0;
  int begin = 0, end = 0;
  int count = 0;
  while ( end < N ) {
    if ( count == M ) {
      if ( resEnd == resBegin || resEnd - resBegin > end - begin ) {
        resBegin = begin;
        resEnd = end;
      }

      if ( dict[S[begin]] ) {
        if ( mapping[S[begin]] <= dict[S[begin]] ) count --;
        mapping[S[begin]] --;
      }
      begin ++;

    } else if ( dict[S[end]] == 0 ) end ++;
    else {
      if ( mapping[S[end]] < dict[S[end]] ) count ++;
      mapping[S[end]] ++;
      end ++;
    }
  }
  return S.substr(resBegin, resEnd - resBegin);
}

