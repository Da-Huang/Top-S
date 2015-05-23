// #redo
vector<int> searchRange(vector<int>& nums, int target) {
  const int N = nums.size();

  int first = 0, last = N;
  while (first < last) {
    int mid = first + (last - first) / 2;
    if (nums[mid] < target) first = mid + 1;
    else last = mid;
  }
  int rl = first;

  last = N;
  while (first < last) {
    int mid = first + (last - first) / 2;
    if (nums[mid] <= target) first = mid + 1;
    else last = mid;
  }
  int rr = first;

  if (rl == rr) return {-1, -1};
  return {rl, rr - 1};
}
