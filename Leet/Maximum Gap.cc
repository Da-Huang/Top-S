// #redo
int maximumGap(vector<int>& nums) {
  const int N = nums.size();
  if (N < 2) return 0;
  int MIN = *min_element(nums.begin(), nums.end());
  int MAX = *max_element(nums.begin(), nums.end());
  int D = max((MAX - MIN + N - 2) / (N - 1), 1);
  int mins[N], maxs[N];
  fill(mins, mins + N, 0);
  fill(maxs, maxs + N, -1);

  for (int num : nums) {
    int bucket = (num - MIN) / D;
    if (mins[bucket] > maxs[bucket]) {
      mins[bucket] = maxs[bucket] = num;
    } else {
      mins[bucket] = min(mins[bucket], num);
      maxs[bucket] = max(maxs[bucket], num);
    }
  }
  int ans = 0;
  int i = 0;
  for (int j = 1; j < N; ++ j) {
    if (mins[j] <= maxs[j]) {
      ans = max(ans, mins[j] - maxs[i]);
      i = j;
    }
  }
  return ans;
}
