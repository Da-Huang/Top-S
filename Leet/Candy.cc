// #redo
int candy(vector<int>& ratings) {
  const int N = ratings.size();
  int ans = 0;
  int begin = 0;
  while (begin < N) {
    int p = begin;
    while (p + 1 < N && ratings[p + 1] > ratings[p]) ++ p;
    int v = p;
    while (v + 1 < N && ratings[v + 1] < ratings[v]) ++ v;

    int dmax = max(p - begin, v - p);
    int dmin = min(p - begin, v - p);
    ans += (dmax + 1) * dmax / 2;
    ans += dmax + 1;
    ans += (dmin + 1) * dmin / 2;

    if (v == p || v == N - 1) begin = v + 1;
    else {
      begin = v;
      -- ans;
    }
  }
  return ans;
}
