bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
  vector<int> graph[numCourses];
  int count[numCourses];
  memset(count, 0, sizeof(count));

  for (auto &pr : prerequisites) {
    graph[pr.second].push_back(pr.first);
    ++ count[pr.first];
  }

  stack<int> stk;
  for (int i = 0; i < numCourses; ++ i) {
    if (count[i] == 0) stk.push(i);
  }
  while (!stk.empty()) {
    int i = stk.top();
    stk.pop();
    for (int u : graph[i]) {
      if (-- count[u] == 0) {
        stk.push(u);
      }
    }
  }
  for (int i = 0; i < numCourses; ++ i) {
    if (count[i]) return false;
  }
  return true;
}
