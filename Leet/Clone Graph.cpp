// #redo
UndirectedGraphNode *__cloneGraph(UndirectedGraphNode *node, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> &MAP) {
  if (node == NULL) return NULL;
  if (MAP.find(node) != MAP.end()) return MAP[node];
  UndirectedGraphNode *newNode = MAP[node] = new UndirectedGraphNode(node->label);
  for (UndirectedGraphNode *neighbor : node->neighbors) {
    newNode->neighbors.push_back(__cloneGraph(neighbor, MAP));
  }
  return newNode;
}

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
  unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> MAP;
  return __cloneGraph(node, MAP);
}


// #version2
UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
  if (node == NULL) return NULL;
  unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> MAP;
  stack<UndirectedGraphNode*> stk;
  MAP[node] = new UndirectedGraphNode(node->label);
  stk.push(node);
  while (!stk.empty()) {
    UndirectedGraphNode *node = stk.top();
    stk.pop();
    for (UndirectedGraphNode *neighbor : node->neighbors) {
      if (MAP.find(neighbor) == MAP.end()) {
        stk.push(neighbor);
        MAP[neighbor] = new UndirectedGraphNode(neighbor->label);
      }
      MAP[node]->neighbors.push_back(MAP[neighbor]);
    }
  }
  return MAP[node];
}
