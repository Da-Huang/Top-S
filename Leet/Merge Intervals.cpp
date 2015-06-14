// Redo
vector<Interval> merge(vector<Interval>& intervals) {
  sort(intervals.begin(), intervals.end(), [] (const Interval &i1, const Interval &i2) {
      return i1.start < i2.start;
      });
  vector<Interval> ans;
  if (intervals.empty()) return ans;

  Interval tmp = intervals.front();
  for (size_t i = 1; i < intervals.size(); ++ i) {
    if (intervals[i].start <= tmp.end) {
      tmp.end = max(intervals[i].end, tmp.end);
    } else {
      ans.push_back(tmp);
      tmp = intervals[i];
    }
  }
  ans.push_back(tmp);
  return ans;
}
