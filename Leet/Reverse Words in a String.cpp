// #redo
void reverseWords(string &s) {
  const int N = s.size();
  int k = 0;
  int begin = 0;
  while (begin < N && s[begin] == ' ') ++ begin;
  while (begin < N) {
    int end = begin + 1;
    while (end < N && s[end] != ' ') ++ end;
    reverse(s.begin() + begin, s.begin() + end);
    copy(s.begin() + begin, s.begin() + end, s.begin() + k);
    k += end - begin;
    begin = end;
    while (begin < N && s[begin] == ' ') ++ begin;
    if (begin < N) s[k ++] = ' ';
  };
  s.resize(k);
  reverse(s.begin(), s.end());
}
