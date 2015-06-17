int majorityElement(vector<int>& nums) {
  int n, count = 0;
  for (int num : nums) {
    if (count == 0) {
      count = 1;
      n = num;
    } else if (n == num) {
      ++ count;
    } else {
      -- count;
    }
  }
  return n;
}
