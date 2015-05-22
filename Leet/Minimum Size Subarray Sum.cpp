// #redo
int minSubArrayLen(int s, vector<int>& nums) {
  const int N = nums.size();
  int ans = 0;
  int sum = 0, i = 0, j = 0;
  while (i < N) {
    if (j == N || sum >= s) sum -= nums[i ++];
    else sum += nums[j ++];
    if (sum >= s && (ans == 0 || ans > j - i)) ans = j - i;
  }
  return ans;
}
