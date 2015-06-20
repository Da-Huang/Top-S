// #redo
int calculateMinimumHP(vector<vector<int>>& dungeon) {
  const int M = dungeon.size();
  if (M == 0) return 0;
  const int N = dungeon[0].size();
  if (N == 0) return 0;

  int hp[M][N];
  hp[M-1][N-1] = max(1 - dungeon[M-1][N-1], 1);
  for (int i = M - 2; i >= 0; -- i) {
    hp[i][N-1] = max(hp[i+1][N-1] - dungeon[i][N-1], 1);
  }
  for (int j = N - 2; j >= 0; -- j) {
    hp[M-1][j] = max(hp[M-1][j+1] - dungeon[M-1][j], 1);
  }
  for (int i = M - 2; i >= 0; -- i) {
    for (int j = N - 2; j >= 0; -- j) {
      hp[i][j] = max(min(hp[i+1][j], hp[i][j+1]) - dungeon[i][j], 1);
    }
  }
  return hp[0][0];
}
