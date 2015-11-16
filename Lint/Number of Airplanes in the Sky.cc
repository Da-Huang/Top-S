int countOfAirplanes(vector<Interval> &airplanes) {
  vector<pair<int, int>> flights;
  for (const Interval &interval : airplanes) {
    flights.push_back(make_pair(interval.start, 1));
    flights.push_back(make_pair(interval.end, -1));
  }
  sort(flights.begin(), flights.end());
  int count = 0;
  int ans = 0;
  for (const auto &p : flights) {
    count += p.second;
    ans = max(ans, count);
  }
  return ans;
}
