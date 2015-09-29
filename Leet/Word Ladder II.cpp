// #redo
void __buildPath(unordered_map<string, int> &dis, vector<string> &v,
                 vector<vector<string>> &ans) {
  int curDis = dis[v.back()];
  if (curDis == 0) {
    ans.push_back(v);
    return;
  }
  v.push_back(v.back());
  for (size_t i = 0; i < v.back().size(); ++i) {
    char ci = v.back()[i];
    for (v.back()[i] = 'a'; v.back()[i] <= 'z'; ++v.back()[i]) {
      if (dis.find(v.back()) != dis.end() && dis[v.back()] == curDis - 1) {
        __buildPath(dis, v, ans);
      }
    }
    v.back()[i] = ci;
  }
  v.pop_back();
}

vector<vector<string>> findLadders(string start, string end,
                                   unordered_set<string> &dict) {
  unordered_map<string, int> dis;
  queue<string> que;
  que.push(start);
  dis[start] = 0;
  while (!que.empty()) {
    string word = que.front();
    que.pop();
    int curDis = dis[word];
    if (word == end) break;
    for (size_t i = 0; i < word.size(); ++i) {
      char ci = word[i];
      for (word[i] = 'a'; word[i] <= 'z'; ++word[i]) {
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

// #version2
void __findLadders(const unordered_map<string, int> &dist_map,
                   vector<vector<string>> &ans, vector<string> &v) {
  string item = v.back();
  int dist = dist_map.at(item);

  if (dist == 0) {
    ans.push_back(v);
    reverse(ans.back().begin(), ans.back().end());
    return;
  }

  for (char &c : item) {
    char oc = c;
    for (c = 'a'; c <= 'z'; ++c) {
      auto it = dist_map.find(item);
      if (it != dist_map.end() && it->second == dist - 1) {
        v.push_back(item);
        __findLadders(dist_map, ans, v);
        v.pop_back();
      }
    }
    c = oc;
  }
}

// Each item is a path.
vector<vector<string>> findLadders(const string &start, const string &end,
                                   const unordered_set<string> &dict) {
  if (dict.find(start) == dict.end()) return {};
  queue<string> que;
  unordered_map<string, int> dist_map;
  dist_map[start] = 0;
  que.push(start);
  while (!que.empty()) {
    string item = que.front();
    que.pop();
    int dist = dist_map[item];
    if (item == end) break;
    for (char &c : item) {
      char oc = c;
      for (c = 'a'; c <= 'z'; ++c) {
        if (dict.find(item) != dict.end() &&
            dist_map.find(item) == dist_map.end()) {
          dist_map[item] = dist + 1;
          que.push(item);
        }
      }
      c = oc;
    }
  }
  if (dist_map.find(end) == dist_map.end()) return {};
  vector<vector<string>> ans;
  vector<string> v;
  v.push_back(end);
  __findLadders(dist_map, ans, v);
  return ans;
}
