// #redo
int minimumSize(vector<int> &nums, int s) {
  int i = 0, j = 0;
  int sum = 0;
  int ans = -1;
  while (i < (int)nums.size()) {
    if (j < (int)nums.size() && sum <= s)
      sum += nums[j++];
    else
      sum -= nums[i++];
    if (sum >= s) {
      if (ans == -1 || ans > j - i) {
        ans = j - i;
      }
    }
  }
  return ans;
}
