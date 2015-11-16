int lengthOfLastWord(string s) {
  const int N = s.size();
  int j = N - 1;
  while (j >= 0 && s[j] == ' ') -- j;
  int i = j;
  while (i >= 0 && s[i] != ' ') -- i;
  return j - i;
}
