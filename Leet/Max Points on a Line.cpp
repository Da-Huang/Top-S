int maxPoints(vector<Point> &points) {
  const int N = points.size();
  int res = 0;
  auto lessP = [] (const Point &p1, const Point &p2) {
    if ( p1.x != p2.x ) return p1.x < p2.x;
    return p1.y < p2.y;
  };
  sort(points.begin(), points.end(), lessP);
  auto lessK = [] (const Point &p1, const Point &p2) {
    return p1.y * p2.x < p2.y * p1.x;
  };
  int begin = 0;
  while ( begin < N ) {
    int end = begin + 1;
    while ( end < N && !lessP(points[begin], points[end]) ) end ++;
    vector<Point> K;
    for (int j = end; j < N; j ++) {
      const int deltaX = points[begin].x - points[j].x;
      const int deltaY = points[begin].y - points[j].y;
      K.push_back(Point(deltaX, deltaY));
    }
    res = max(res, end - begin);
    sort(K.begin(), K.end(), lessK);
    int beginK = 0;
    while ( beginK < (int) K.size() ) {
      int endK = beginK + 1;
      while ( endK < (int) K.size() && !lessK(K[beginK], K[endK]) ) endK ++;
      res = max(res, endK - beginK + end - begin);
      beginK = endK;
    }

    begin = end;
  }
  return res;
}
