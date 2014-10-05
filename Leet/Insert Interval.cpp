// Redo
vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
  vector<Interval> res;
  const int N = intervals.size();
  int i = 0;
  while ( i < N && intervals[i].end < newInterval.start ) res.push_back(intervals[i ++]);
  if ( i >= N || intervals[i].start > newInterval.end ) {
    res.push_back(newInterval);
  } else {
    int end = i;
    while ( end < N && intervals[end].start <= newInterval.end ) end ++;
    res.push_back(Interval(
          min(intervals[i].start, newInterval.start),
          max(intervals[end - 1].end, newInterval.end)
          ));
    i = end;
  }
  while ( i < N ) res.push_back(intervals[i ++]);
  return res;
}

