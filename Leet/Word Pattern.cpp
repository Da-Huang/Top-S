// #redo
bool wordPattern(string pattern, string str) {
  int i = 0;
  string cmap[26];
  unordered_set<string> wset;
  for (char c : pattern) {
    if (i >= (int)str.size()) return false;
    int j = i + 1;
    while (j < str.size() && str[j] != ' ') ++j;
    string word = str.substr(i, j - i);
    i = j + 1; // skip space

    if (cmap[c - 'a'].empty()) {
      if (wset.find(word) != wset.end()) return false;
      wset.insert(cmap[c - 'a'] = word);
    } else if (cmap[c - 'a'] != word) return false;
  }
  return i >= (int)str.size();
}
