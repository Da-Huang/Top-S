// Redo
vector<int> findSubstring(string s, vector<string>& words) {
  const int N = s.size();
  const int M = words.size();
  unordered_map<string, int> dict;
  for (auto &word : words) ++ dict[word];

  vector<int> ans;
  if (M == 0) return ans;
  const int W = words[0].size();

  for (int k = 0; k < W; ++ k) {
    unordered_map<string, int> mapping;
    int match = 0;
    int i = k, j = k;
    while (i + M * W <= N) { // NOTE: no need to judge j + W <= N
      string word = s.substr(j, W);
      if (dict.find(word) == dict.end()) {
        j += W;
        i = j;
        mapping.clear();
        match = 0;

      } else if (mapping[word] == dict[word]) {
        -- mapping[s.substr(i, W)];
        -- match;
        i += W;

      } else {
        ++ mapping[word];
        if (++ match == M) ans.push_back(i);
        j += W;
      }
    }
  }
  return ans;
}
