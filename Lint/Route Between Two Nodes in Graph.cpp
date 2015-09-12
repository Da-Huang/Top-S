bool hasRoute(vector<DirectedGraphNode*> graph, DirectedGraphNode* s,
              DirectedGraphNode* t) {
  stack<DirectedGraphNode*> stk;
  unordered_set<DirectedGraphNode*> visited;
  visited.insert(s);
  stk.push(s);
  while (!stk.empty()) {
    DirectedGraphNode* node = stk.top();
    stk.pop();
    if (node == t) return true;
    for (DirectedGraphNode* neighbor : node->neighbors) {
      if (visited.find(neighbor) != visited.end()) continue;
      visited.insert(neighbor);
      stk.push(neighbor);
    }
  }
  return false;
}
