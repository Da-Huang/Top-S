// #redo
vector<vector<int>> submatrixSum(vector<vector<int>>& matrix) {
  const int M = matrix.size();
  if (M == 0) return {};
  const int N = matrix[0].size();
  if (N == 0) return {};
  
  int buffer[N];
  for (int i = 0; i < M; ++i) {
    memset(buffer, 0, sizeof(buffer));
    for (int j = i; j < M; ++j) {
      unordered_map<int, int> mapping;
      int sum = 0;
      mapping[sum] = 0;
      for (int k = 0; k < N; ++k) {
        buffer[k] += matrix[j][k];
        sum += buffer[k];
        if (mapping.find(sum) != mapping.end()) {
          return {{i,mapping[sum]}, {j,k}};
        }
        mapping[sum] = k + 1;
      }
    }
  }
  return {};
}
