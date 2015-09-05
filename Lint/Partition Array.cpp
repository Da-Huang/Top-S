// #redo
int partitionArray(vector<int> &nums, int k) {
  int first = 0, last = (int)nums.size() - 1;
  while (first <= last) {
    if (nums[first] < k)
      ++first;
    else if (nums[last] >= k)
      --last;
    else {
      swap(nums[first], nums[last]);
      ++first;
      --last;
    }
  }
  return first;
}
