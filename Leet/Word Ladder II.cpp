// #redo
void __buildPath(unordered_map<string, int> &dis, vector<string> &v, vector<vector<string>> &ans) {
  int curDis = dis[v.back()];
  if (curDis == 0) {
    ans.push_back(v);
    return;
  }
  v.push_back(v.back());
  for (size_t i = 0; i < v.back().size(); ++ i) {
    char ci = v.back()[i];
    for (v.back()[i] = 'a'; v.back()[i] <= 'z'; ++ v.back()[i]) {
      if (dis.find(v.back()) != dis.end() && dis[v.back()] == curDis - 1) {
        __buildPath(dis, v, ans);
      }
    }
    v.back()[i] = ci;
  }
  v.pop_back();
}

vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
  unordered_map<string, int> dis;
  queue<string> que;
  que.push(start);
  dis[start] = 0;
  while (!que.empty()) {
    string word = que.front();
    que.pop();
    int curDis = dis[word];
    if (word == end) break;
    for (size_t i = 0; i < word.size(); ++ i) {
      char ci = word[i];
      for (word[i] = 'a'; word[i] <= 'z'; ++ word[i]) {
        if (dict.find(word) != dict.end() && dis.find(word) == dis.end()) {
          que.push(word);
          dis[word] = curDis + 1;
        }
      }
      word[i] = ci;
    }
  }
  vector<vector<string>> ans;
  vector<string> v;
  if (dis.find(end) == dis.end()) return ans;
  v.push_back(end);
  __buildPath(dis, v, ans);
  for (auto &v : ans) {
    reverse(v.begin(), v.end());
  }
  return ans;
}
