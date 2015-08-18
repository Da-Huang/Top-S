// #redo
void* __lookup(void* node) {
  void* ans = node;
  while (*(void**)ans) {
    ans = *(void**)ans;
  }
  while (node != ans) {
    void* next_node = *(void**)node;
    *(void**)node = ans;
    node = next_node;
  }
  return ans;
}

vector<int> numIslands2(int n, int m, vector<Point>& operators) {
  vector<vector<bool>> is_island(n, vector<bool>(m, false));
  void* union_set[n][m];
  memset(union_set, 0, sizeof(union_set));
  vector<int> ans;
  int count = 0;
  for (const Point &point : operators) {
    is_island[point.x][point.y] = true;
    ++count;
    static const int direction[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for (int k = 0; k < 4; ++k) {
      int i = point.x + direction[k][0];
      int j = point.y + direction[k][1];
      if (0 <= i && i < n && 0 <= j && j < m && is_island[i][j]) {
        void* point_root = __lookup(&union_set[point.x][point.y]);
        void* another_root = __lookup(&union_set[i][j]);
        if (point_root != another_root) {  
          *(void**)point_root = another_root;
          --count;
        }
      }
    }
    ans.push_back(count);
  }
  return ans;
}
