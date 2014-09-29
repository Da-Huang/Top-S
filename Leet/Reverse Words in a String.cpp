void reverseWords(string &s) {
  const int N = s.length();
  int len = 0, begin = 0;
  while ( begin < N && s[begin] == ' ' ) begin ++;
  while ( begin < N ) {
    int end = begin + 1;
    while ( end < N && s[end] != ' ' ) end ++;
    reverse(s.begin() + begin, s.begin() + end);
    copy(s.begin() + begin, s.begin() + end, s.begin() + len);
    len += end - begin;
    while ( end < N && s[end] == ' ' ) end ++;
    begin = end;
    if ( begin < N ) s[len ++] = ' ';
  }
  s.resize(len);
  reverse(s.begin(), s.end());
}
