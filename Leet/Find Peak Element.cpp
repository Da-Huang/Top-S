int findPeakElement(vector<int>& nums) {
  const int N = nums.size();
  if (N == 0) return INT_MIN;
  int first = 0, last = N - 1;
  while (first < last) {
    int mid = first + (last - first) / 2;
    if (nums[mid] < nums[mid + 1]) first = mid + 1;
    else last = mid;
  }
  return first;
}
