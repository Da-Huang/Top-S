vector<int> productExceptSelf(vector<int>& nums) {
  const int N = nums.size();
  vector<int> ans(N);
  int val = 1;
  for (int i = 0; i < N; ++i) {
    ans[i] = val;
    val *= nums[i];
  }
  val = 1;
  for (int i = N - 1; i >= 0; --i) {
    ans[i] *= val;
    val *= nums[i];
  }
  return ans;
}
