vector<vector<string>> getPaths(const string &start, const string &end, unordered_map<string, int> &path) {
  vector<vector<string>> res;
  if ( start == end ) {
    res.push_back(vector<string>(1, start));
    return res;
  }

  const int N = end.length();
  for (int i = 0; i < N; i ++) {
    string prev = end;
    for (char c = 'a'; c <= 'z'; c ++) {
      if ( c != end[i] ) {
        prev[i] = c;
        auto it = path.find(prev);
        if ( it != path.end() && it->second == path[end] - 1 ) {
          vector<vector<string>> subRes = getPaths(start, prev, path);
          for (auto &item : subRes) {
            item.push_back(end);
            res.push_back(item);
          }
        }
      }
    }
  }
  return res;
}

vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
  const int N = start.length();
  unordered_map<string, int> path;
  path[start] = 0;
  queue<string> q;
  q.push(start);
  while ( !q.empty() ) {
    string str = q.front();
    q.pop();
    if ( str == end ) break;
    for (int i = 0; i < N; i ++) {
      string newStr = str;
      for (char c = 'a'; c <= 'z'; c ++) {
        if ( c != str[i] ) {
          newStr[i] = c;
          if ( dict.find(newStr) != dict.end() && path.find(newStr) == path.end() ) {
            path[newStr] = path[str] + 1;
            q.push(newStr);
          }
        }
      }
    }
  }
  return getPaths(start, end, path);
}

