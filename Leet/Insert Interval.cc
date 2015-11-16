// #redo
vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
  vector<Interval> ans;
  size_t i = 0;
  while (i < intervals.size() && intervals[i].end < newInterval.start) ans.push_back(intervals[i ++]);
  while (i < intervals.size() && intervals[i].start <= newInterval.end) {
    newInterval.start = min(newInterval.start, intervals[i].start);
    newInterval.end = max(newInterval.end, intervals[i].end);
    ++ i;
  }
  ans.push_back(newInterval);
  while (i < intervals.size()) ans.push_back(intervals[i ++]);
  return ans;
}
