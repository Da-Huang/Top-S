// Redo
string minWindow(string s, string t) {
  const int N = s.size();
  const int M = t.size();
  int dict[128], mapping[128];
  memset(dict, 0, sizeof(dict));
  memset(mapping, 0, sizeof(mapping));

  for (auto c : t) ++ dict[c];
  int minBegin = 0, minEnd = 0;
  int i = 0, j = 0;
  int match = 0;
  while (i + M <= N) {
    if (match < M) {
      if (j >= N) break;
      if (++ mapping[s[j]] <= dict[s[j]]) ++ match;
      ++ j;

    } else {
      if (minEnd == minBegin || minEnd - minBegin > j - i) {
        minBegin = i;
        minEnd = j;
      }
      if (-- mapping[s[i]] < dict[s[i]]) -- match;
      ++ i;
    }
  }
  return s.substr(minBegin, minEnd - minBegin);
}
