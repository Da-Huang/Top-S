UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
  if ( node == NULL ) return NULL;
  unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mapping;
  stack<UndirectedGraphNode*> nodeStack;
  nodeStack.push(node);
  mapping[node] = new UndirectedGraphNode(node->label);
  while ( !nodeStack.empty() ) {
    UndirectedGraphNode *cur = nodeStack.top();
    nodeStack.pop();
    for (auto &neighbor : cur->neighbors) {
      if ( mapping.find(neighbor) == mapping.end() ) {
        mapping[neighbor] = new UndirectedGraphNode(neighbor->label);
        nodeStack.push(neighbor);
      }
      mapping[cur]->neighbors.push_back(mapping[neighbor]);
    }
  }
  return mapping[node];
}
