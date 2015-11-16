// #redo
int removeDuplicates(vector<int>& nums) {
  int k = 0;
  size_t begin = 0;
  while (begin < nums.size()) {
    size_t end = begin + 1;
    while (end < nums.size() && nums[end] == nums[begin]) ++ end;
    for (size_t i = begin; i < begin + 2 && i < end; ++ i) nums[k ++] = nums[i];
    begin = end;
  }
  return k;
}


// #version2
int removeDuplicates(vector<int>& nums) {
  if (nums.size() == 0) return 0;
  int k = 1;
  int count = 1;
  for (size_t i = 1; i < nums.size(); ++ i) {
    if (nums[i] == nums[i - 1]) {
      if (++ count <= 2) nums[k ++] = nums[i];
    } else {
      count = 1;
      nums[k ++] = nums[i];
    }
  }
  return k;
}
