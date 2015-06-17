// #redo
int findMin(vector<int>& nums) {
  const int N = nums.size();
  int first = 0, last = N;
  while (first < last) {
    int mid = first + (last - first) / 2;
    if (nums[mid] < nums[first]) last = mid;
    else {
      first = mid + 1;
      if (first < last && nums[first] < nums[mid]) break;
    }
  }
  if (N == 0) return INT_MAX;
  return first < N ? nums[first] : nums[0];
}
