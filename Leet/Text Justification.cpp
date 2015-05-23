// #redo
vector<string> fullJustify(vector<string>& words, int maxWidth) {
  vector<string> ans;
  if (words.size() == 0) return ans;

  size_t i = 0, size = words[i].size();
  for (size_t j = 1; j < words.size(); ++ j) {
    if (size + words[j].size() + 1 <= maxWidth) size += 1 + words[j].size();
    else {
      string line = words[i];
      if (i + 1 == j) {
        line.resize(maxWidth, ' ');

      } else {
        int outSpaces = maxWidth - size;
        int spaces = outSpaces / (j - i - 1);
        int moreSpace = outSpaces % (j - i - 1);
        int k;
        for (k = i+1; k <= i+moreSpace; ++ k) {
          line.insert(line.end(), spaces + 2, ' ');
          line += words[k];
        }
        for (; k < j; ++ k) {
          line.insert(line.end(), spaces + 1, ' ');
          line += words[k];
        }
      }

      ans.push_back(line);
      i = j;
      size = words[j].size();
    }
  }
  string line = words[i];
  for (size_t j = i+1; j < words.size(); ++ j) {
    line += " " + words[j];
  }
  line.resize(maxWidth, ' ');
  ans.push_back(line);
  return ans;
}
