vector<string> longestWords(vector<string> &dictionary) {
  size_t ans_length = 0;
  for (const string &word : dictionary) {
    ans_length = max(ans_length, word.size());
  }
  vector<string> ans;
  for (const string &word : dictionary) {
    if (word.size() == ans_length) ans.push_back(word);
  }
  return ans;
}
