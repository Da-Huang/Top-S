// #redo
int trapRainWater(vector<vector<int>> &heights) {
  const int M = heights.size();
  if (M <= 2) return 0;
  const int N = heights[0].size();
  if (N <= 2) return 0;
  vector<tuple<int, int, int>> pq;
  auto __less = [](const tuple<int, int, int> &cell1,
                   const tuple<int, int, int> &cell2) {
    return get<2>(cell1) > get<2>(cell2);
  };
  vector<vector<bool>> visited(M, vector<bool>(N, false));
  visited[0][0] = visited[0][N - 1] = visited[M - 1][0] =
      visited[M - 1][N - 1] = true;
  for (int j = 1; j + 1 < N; ++j) {
    pq.push_back(make_tuple(0, j, heights[0][j]));
    pq.push_back(make_tuple(M - 1, j, heights[M - 1][j]));
    visited[0][j] = visited[M - 1][j] = true;
  }
  for (int i = 1; i + 1 < M; ++i) {
    pq.push_back(make_tuple(i, 0, heights[i][0]));
    pq.push_back(make_tuple(i, N - 1, heights[i][N - 1]));
    visited[i][0] = visited[i][N - 1] = true;
  }
  make_heap(pq.begin(), pq.end(), __less);
  int ans = 0;
  while (!pq.empty()) {
    int i, j, h;
    tie(i, j, h) = pq.front();
    pop_heap(pq.begin(), pq.end(), __less);
    pq.pop_back();
    ans += h - heights[i][j];
    if (i > 0 && !visited[i - 1][j]) {
      pq.push_back(make_tuple(i - 1, j, max(h, heights[i - 1][j])));
      push_heap(pq.begin(), pq.end(), __less);
      visited[i - 1][j] = true;
    }
    if (j > 0 && !visited[i][j - 1]) {
      pq.push_back(make_tuple(i, j - 1, max(h, heights[i][j - 1])));
      push_heap(pq.begin(), pq.end(), __less);
      visited[i][j - 1] = true;
    }
    if (i + 1 < M && !visited[i + 1][j]) {
      pq.push_back(make_tuple(i + 1, j, max(h, heights[i + 1][j])));
      push_heap(pq.begin(), pq.end(), __less);
      visited[i + 1][j] = true;
    }
    if (j + 1 < N && !visited[i][j + 1]) {
      pq.push_back(make_tuple(i, j + 1, max(h, heights[i][j + 1])));
      push_heap(pq.begin(), pq.end(), __less);
      visited[i][j + 1] = true;
    }
  }
  return ans;
}

// #version2
int trapRainWater(vector<vector<int>> &heights) {
  const int M = heights.size();
  if (M <= 2) return 0;
  const int N = heights[0].size();
  if (N <= 2) return 0;
  vector<vector<bool>> visited(M, vector<bool>(N));
  auto __less = [](const tuple<int, int, int> &cell1,
                   const tuple<int, int, int> &cell2) {
    return get<2>(cell1) > get<2>(cell2);
  };
  vector<tuple<int, int, int>> pq;
  for (int i = 1; i < M - 1; ++i) {
    pq.push_back(make_tuple(i, 0, heights[i][0]));
    pq.push_back(make_tuple(i, N - 1, heights[i][N - 1]));
  }
  for (int j = 1; j < N - 1; ++j) {
    pq.push_back(make_tuple(0, j, heights[0][j]));
    pq.push_back(make_tuple(M - 1, j, heights[M - 1][j]));
  }
  make_heap(pq.begin(), pq.end(), __less);

  static int dirs[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  int ans = 0;
  while (!pq.empty()) {
    int row, col, height;
    tie(row, col, height) = pq.front();
    pop_heap(pq.begin(), pq.end(), __less);
    pq.pop_back();

    for (int k = 0; k < 4; ++k) {
      int ii = row + dirs[k][0];
      int jj = col + dirs[k][1];
      if (ii > 0 && ii < M - 1 && jj > 0 && jj < N - 1 && !visited[ii][jj]) {
        visited[ii][jj] = true;
        int new_height = max(height, heights[ii][jj]);
        ans += new_height - heights[ii][jj];
        pq.push_back(make_tuple(ii, jj, new_height));
        push_heap(pq.begin(), pq.end(), __less);
      }
    }
  }
  return ans;
}
