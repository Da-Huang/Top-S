int ladderLength(string start, string end, unordered_set<string> &dict) {
  unordered_map<string, int> path;
  const int N = start.length();
  path[start] = 0;
  queue<string> q;
  q.push(start);
  while ( !q.empty() ) {
    string cur = q.front();
    q.pop();
    if ( cur == end ) return path[cur] + 1;

    for (int i = 0; i < N; i ++) {
      string next = cur;
      for (next[i] = 'a'; next[i] <= 'z'; next[i] ++) {
        if ( next[i] != cur[i] && dict.find(next) != dict.end() && path.find(next) == path.end() ) {
          path[next] = path[cur] + 1;
          q.push(next);
        }
      }
    }
  }
  return 0;
}

