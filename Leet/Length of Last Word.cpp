int lengthOfLastWord(const char *s) {
  const int N = strlen(s);
  int last = N - 1;
  while ( last >= 0 && s[last] == ' ' ) last --;
  if ( last < 0 ) return 0;
  int rend = last - 1;
  while ( rend >= 0 && s[rend] != ' ' ) rend --;
  return last - rend;
}

