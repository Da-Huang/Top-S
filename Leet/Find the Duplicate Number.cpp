// #redo
bool __findDuplicate(const vector<int>& nums, int n) {
  int count = 0;
  for (int num : nums)
    if (num <= n) ++count;
  return count > n;
}

int findDuplicate(vector<int>& nums) {
  if (nums.size() < 2) return INT_MIN;
  const int N = (int)nums.size();
  int first = 1, last = N;
  while (first < last) {
    int mid = first + (last - first) / 2;
    if (__findDuplicate(nums, mid))
      last = mid;
    else
      first = mid + 1;
  }
  return first;
}
