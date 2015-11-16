// #redo
int maxPoints(vector<Point>& points) {
  const int N = points.size();
  int ans = 0;
  auto lessp = [](const Point &p1, const Point &p2) {
    if (p1.x < p2.x) return true;
    if (p1.x > p2.x) return false;
    return p1.y < p2.y;
  };
  sort(points.begin(), points.end(), lessp);

  auto lessk = [](const Point &k1, const Point &k2) {
    return k1.y * k2.x < k2.y * k1.x;
  };

  int begin = 0;
  while (begin < N) {
    int end = begin + 1;
    while (end < N && !lessp(points[begin], points[end])) ++ end;
    ans = max(ans, end - begin);
    vector<Point> ks;
    for (int j = end; j < N; ++ j)
      ks.push_back(Point(points[j].x - points[begin].x, points[j].y - points[begin].y));
    sort(ks.begin(), ks.end(), lessk);
    size_t kbegin = 0;
    while (kbegin < ks.size()) {
      size_t kend = kbegin + 1;
      while (kend < ks.size() && !lessk(ks[kbegin], ks[kend])) ++ kend;
      ans = max(ans, end - begin + (int) (kend - kbegin));
      kbegin = kend;
    }
    begin = end;
  }

  return ans;
}


// #version2
int maxPoints(vector<Point>& points) {
  const int N = points.size();
  int ans = 0;
  auto lessp = [](const Point &p1, const Point &p2) {
    if (p1.x < p2.x) return true;
    if (p1.x > p2.x) return false;
    return p1.y < p2.y;
  };
  sort(points.begin(), points.end(), lessp);

  int begin = 0;
  while (begin < N) {
    int end = begin + 1;
    while (end < N && !lessp(points[begin], points[end])) ++ end;
    ans = max(ans, end - begin);
    unordered_map<double, int> ks;
    for (int j = end; j < N; ++ j) {
      double xdelta = points[j].x - points[begin].x;
      double ydelta = points[j].y - points[begin].y;
      if (xdelta == 0) ++ ks[(double) INT_MAX + 1];
      else ++ ks[ydelta / xdelta];
    }
    for (auto &p : ks) {
      ans = max(ans, p.second + end - begin);
    }
    begin = end;
  }

  return ans;
}
