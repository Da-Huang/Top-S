// #redo
vector<vector<int>> connectedSet(vector<UndirectedGraphNode *> &nodes) {
  vector<vector<int>> ans;
  unordered_set<int> visited;

  for (UndirectedGraphNode *node : nodes) {
    if (visited.find(node->label) != visited.end()) continue;

    ans.push_back({});
    stack<UndirectedGraphNode *> stk;
    stk.push(node);
    visited.insert(node->label);

    while (!stk.empty()) {
      UndirectedGraphNode *node = stk.top();
      stk.pop();
      ans.back().push_back(node->label);

      for (UndirectedGraphNode *neighbor : node->neighbors) {
        if (visited.find(neighbor->label) != visited.end()) continue;
        visited.insert(neighbor->label);
        stk.push(neighbor);
      }
    }
  }

  for (auto &v : ans) sort(v.begin(), v.end());
  return ans;
}

// #version2
vector<vector<int>> connectedSet(vector<UndirectedGraphNode *> &nodes) {
  vector<vector<int>> ans;
  unordered_set<UndirectedGraphNode *> visited;

  for (UndirectedGraphNode *node : nodes) {
    if (visited.find(node) != visited.end()) continue;

    ans.push_back({});
    stack<UndirectedGraphNode *> stk;
    stk.push(node);
    visited.insert(node);

    while (!stk.empty()) {
      UndirectedGraphNode *node = stk.top();
      stk.pop();
      ans.back().push_back(node->label);

      for (UndirectedGraphNode *neighbor : node->neighbors) {
        if (visited.find(neighbor) != visited.end()) continue;
        visited.insert(neighbor);
        stk.push(neighbor);
      }
    }
  }

  for (auto &v : ans) sort(v.begin(), v.end());
  return ans;
}
