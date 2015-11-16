// #redo
vector<vector<int>> connectedSet2(vector<DirectedGraphNode*>& nodes) {
  vector<vector<size_t>> reverse_nodes(nodes.size());
  unordered_map<int, size_t> label_index;
  for (size_t i = 0; i < nodes.size(); ++i) {
    label_index[nodes[i]->label] = i;
  }
  for (size_t i = 0; i < nodes.size(); ++i) {
    for (DirectedGraphNode* neighbor : nodes[i]->neighbors) {
      size_t v = label_index[neighbor->label];
      reverse_nodes[v].push_back(i);
    }
  }
  
  vector<vector<int>> ans;
  vector<bool> visited(nodes.size());
  for (size_t i = 0; i < nodes.size(); ++i) {
    if (visited[i]) continue;
    
    ans.push_back({});
    stack<int> stk;
    stk.push(i);
    visited[i] = true;
    while (!stk.empty()) {
      int u = stk.top();
      stk.pop();
      ans.back().push_back(nodes[u]->label);
      
      for (DirectedGraphNode* neighbor : nodes[u]->neighbors) {
        int v = label_index[neighbor->label];
        if (!visited[v]) {
          visited[v] = true;
          stk.push(v);
        }
      }
      for (size_t neighbor : reverse_nodes[u]) {
        if (!visited[neighbor]) {
          visited[neighbor] = true;
          stk.push(neighbor);
        }
      }
    }
  }
  
  for (auto &v : ans) {
    sort(v.begin(), v.end());
  }
  return ans;
}
