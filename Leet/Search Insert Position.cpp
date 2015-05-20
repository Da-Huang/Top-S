int searchInsert(vector<int>& nums, int target) {
  int N = nums.size();
  if (N == 0) return 0;
  int first = 0, last = N - 1;
  while (first < last) {
    int mid = first + (last - first) / 2;
    if (nums[mid] < target) first = mid + 1;
    else last = mid - 1;
  }
  return nums[first] >= target ? first : first + 1;
}
