// #redo
// should promise that it stops when begin jump down to the 2nd segment
bool __search(vector<int> &nums, int target, int begin, int end) {
  while (begin < end) {
    int mid = begin + (end - begin) / 2;
    if (nums[mid] < target) begin = mid + 1;
    else if (nums[mid] > target) end = mid;
    else return true;
  }
  return false;
}

bool search(vector<int>& nums, int target) {
  const int N = nums.size();
  if (N == 0) return false;
  int first = 0, last = N - 1;
  while (first < last) {
    int mid = first + (last - first) / 2;
    if (nums[mid] < nums[first]) last = mid;
    else if (nums[mid] == nums[first]) ++ first;
    else {
      first = mid + 1;
      if (nums[mid] > nums[first]) break;
    }
  }
  return __search(nums, target, 0, first) || __search(nums, target, first, N);
}
