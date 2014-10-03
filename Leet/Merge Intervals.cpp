// Redo
vector<Interval> merge(vector<Interval> &intervals) {
  sort(intervals.begin(), intervals.end(), [] (const Interval &i1, const Interval &i2) {
      return i1.start < i2.start;
      });
  vector<Interval> res;
  int begin = 0;
  const int N = intervals.size();
  while ( begin < N ) {
    int end = begin + 1;
    int s = intervals[begin].start;
    int e = intervals[begin].end;
    while ( end < N && intervals[end].start <= e ) {
      e = max(e, intervals[end].end);
      end ++;
    }
    res.push_back(Interval(s, e));
    begin = end;
  }
  return res;
}

