vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
  vector<int> graph[numCourses];
  int inDegree[numCourses];
  memset(inDegree, 0, sizeof(inDegree));
  for (auto &p : prerequisites) {
    graph[p.second].push_back(p.first);
    ++ inDegree[p.first];
  }
  stack<int> stk;
  for (int i = 0; i < numCourses; ++ i) {
    if (inDegree[i] == 0) stk.push(i);
  }
  vector<int> ans;
  while (!stk.empty()) {
    int i = stk.top();
    stk.pop();
    ans.push_back(i);
    for (int j : graph[i]) {
      if (-- inDegree[j] == 0) stk.push(j);
    }
  }
  for (int d : inDegree) if (d) return {};
  return ans;
}
