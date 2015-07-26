vector<int> maxSlidingWindow(vector<int>& nums, int k) {
  vector<int> ans;
  if (k <= 0) return ans;
  deque<int> qVal, qMax;
  for (int i = 0; i < (int)nums.size(); ++i) {
    if (i >= k) {
      if (qVal.front() == qMax.front()) qMax.pop_front();
      qVal.pop_front();
    }
    qVal.push_back(nums[i]);
    while (!qMax.empty() && qMax.back() < nums[i]) qMax.pop_back();
    qMax.push_back(nums[i]);
    if (i >= k - 1) {
      ans.push_back(qMax.front());
    }
  }
  return ans;
}
