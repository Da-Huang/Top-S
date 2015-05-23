// #redo
int findKthLargest(vector<int>& nums, int k) {
  const int N = nums.size();
  if (N == 0 || k > N) return INT_MIN;
  int first = 0, last = N - 1;
  while (k > 1) {
    int j = first;
    for (int i = first + 1; i <= last; ++ i) {
      if (nums[j] < nums[i]) {
        if (i == j + 1) swap(nums[i], nums[j]);
        else {
          swap(nums[j], nums[j + 1]);
          swap(nums[j], nums[i]);
        }
        ++ j;
      }
    }
    if (j - first == k - 1) return nums[j];
    if (j - first > k - 1) last = j - 1;
    else { // j - first < k - 1
      k -= j - first + 1;
      first = j + 1;
    }
  }
  return *max_element(nums.begin() + first, nums.begin() + last + 1);
}
