int minimumTotal(vector<vector<int> > &triangle) {
  const int N = triangle.size();
  if (N == 0) return 0;
  int v[N];
  v[0] = triangle[0][0];
  for (int i = 1; i < N; ++ i) {
    v[i] = v[i - 1] + triangle[i][i];
    for (int j = i - 1; j > 0; -- j) {
      v[j] = min(v[j], v[j - 1]) + triangle[i][j];
    }
    v[0] += triangle[i][0];
  }
  return *min_element(v, v + N);
}
