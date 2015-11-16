// #redo
int __search(vector<int> &nums, int target, int first, int last) {
  while (first < last) {
    int mid = first + (last - first) / 2;
    if (nums[mid] > target) last = mid;
    else if (nums[mid] < target) first = mid + 1;
    else return mid;
  }
  return -1;
}

int search(vector<int>& nums, int target) {
  int first = 0, last = (int) nums.size();
  while (first < last) {
    int mid = first + (last - first) / 2;
    if (nums[mid] < nums[first]) last = mid;
    else {
      first = mid + 1;
      if (first < last && nums[first] < nums[mid]) break;
    }
  }
  return max(__search(nums, target, 0, first), __search(nums, target, first, (int) nums.size()));
}
