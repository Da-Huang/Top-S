int _FindMinHeightTree(const vector<int> graph[],
                       const vector<pair<int, int>>& edges, int start,
                       int min_sub_height[]) {
  if (min_sub_height[start]) return min_sub_height[start];
  const int M = edges.size();
  int parent, current;
  if (start < M) {
    parent = edges[start].first;
    current = edges[start].second;
  } else {
    parent = edges[start - M].second;
    current = edges[start - M].first;
  }
  int height = 0;
  for (int e : graph[current]) {
    int next = e < M ? edges[e].second : edges[e - M].first;
    if (next == parent) continue;
    height = max(height, _FindMinHeightTree(graph, edges, e, min_sub_height));
  }
  return min_sub_height[start] = ++height;
}

vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
  const int M = edges.size();
  vector<int> graph[n];
  for (int i = 0; i < M; ++i) {
    graph[edges[i].first].push_back(i);
    graph[edges[i].second].push_back(i + M);
  }

  int min_sub_height[M * 2];
  memset(min_sub_height, 0, sizeof(min_sub_height));

  vector<int> ans;
  int min_height = INT_MAX;
  for (int i = 0; i < n; ++i) {
    int height = 0;
    for (int e : graph[i]) {
      height = max(height, _FindMinHeightTree(graph, edges, e, min_sub_height));
    }
    ++height;
    if (height == min_height)
      ans.push_back(i);
    else if (height < min_height) {
      min_height = height;
      ans.clear();
      ans.push_back(i);
    }
  }
  return ans;
}
