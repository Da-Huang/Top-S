// #redo
int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
  unordered_map<string, int> path;
  queue<string> que;
  path[beginWord] = 1;
  que.push(beginWord);
  while (!que.empty()) {
    string word = que.front();
    que.pop();
    int len = path[word];
    if (word == endWord) break;
    for (size_t i = 0; i < word.size(); ++ i) {
      char ci = word[i];
      for (char c = 'a'; c <= 'z'; ++ c) {
        word[i] = c;
        if (wordDict.find(word) != wordDict.end() && path.find(word) == path.end()) {
          path[word] = len + 1;
          que.push(word);
        }
      }
      word[i] = ci;
    }
  }
  return path[endWord];
}
