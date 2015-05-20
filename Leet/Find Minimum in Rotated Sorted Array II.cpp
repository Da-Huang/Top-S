int findMin(vector<int>& nums) {
  const int N = nums.size();
  if (N == 0) return INT_MAX;

  int first = 0, last = N - 1;
  while (first < last && nums[first] >= nums[last]) {
    int mid = first + (last - first) / 2;
    if (nums[mid] > nums[last]) first = mid + 1;
    else if (nums[mid] < nums[first]) last = mid;
    else ++ first;
  }
  return first < N ? nums[first] : nums[0];
}
