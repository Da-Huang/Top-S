// #redo
int kthSmallest(vector<vector<int> > &matrix, int k) {
  const int M = matrix.size();
  if (M == 0) return INT_MIN;
  const int N = matrix[0].size();
  if (N == 0) return INT_MIN;
  
  if (k > M * N) return INT_MIN;
  
  int column_index[M];
  memset(column_index, 0, sizeof(column_index));
  int heap[M];
  for (int i = 0; i < M; ++i) heap[i] = i;
  int heap_size = M;
  
  auto greater_index = [&column_index,&matrix](int i, int j) {
    return matrix[i][column_index[i]] > matrix[j][column_index[j]];
  };
  
  int ans = INT_MIN;
  while (--k >= 0) {
    int i = heap[0];
    ans = matrix[i][column_index[i]];
    pop_heap(heap, heap+heap_size, greater_index);
    --heap_size;
    if (column_index[i] + 1 < N) {
      ++column_index[i];
      heap[heap_size++] = i;
      push_heap(heap, heap+heap_size, greater_index);
    }
  }
  return ans;
}
