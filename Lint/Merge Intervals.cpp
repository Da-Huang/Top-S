// #redo
vector<Interval> merge(vector<Interval> &intervals) {
  const int N = intervals.size();
  if (N == 0) return {};
  sort(intervals.begin(), intervals.end(),
       [](const Interval &i1, const Interval &i2) {
         return i1.start < i2.start;
       });
  vector<Interval> ans;
  Interval interval = intervals[0];
  for (int i = 1; i <= N; ++i) {
    if (i == N || interval.end < intervals[i].start) {
      ans.push_back(interval);
      if (i < N) interval = intervals[i];
    } else {
      interval.end = max(interval.end, intervals[i].end);
    }
  }
  return ans;
}
