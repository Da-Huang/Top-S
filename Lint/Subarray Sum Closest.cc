// #redo
vector<int> subarraySumClosest(vector<int> nums) {
  const int N = nums.size();
  if (N == 0) return {};

  pair<int, int> cum_idxs[N + 1];
  cum_idxs[0] = make_pair(0, 0);
  for (int i = 0; i < N; ++i) {
    cum_idxs[i + 1] = make_pair(cum_idxs[i].first + nums[i], i + 1);
  }
  sort(cum_idxs, cum_idxs + N + 1);
  int ansi = 1;
  for (int i = 2; i <= N; ++i) {
    if (cum_idxs[i].first - cum_idxs[i - 1].first <
        cum_idxs[ansi].first - cum_idxs[ansi - 1].first)
      ansi = i;
  }
  vector<int> ans = {cum_idxs[ansi].second, cum_idxs[ansi - 1].second};
  sort(ans.begin(), ans.end());
  --ans.back();
  return ans;
}
