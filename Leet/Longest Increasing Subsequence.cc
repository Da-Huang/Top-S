// #redo
int lengthOfLIS(vector<int>& nums) {
  vector<int> ans;
  for (int i = 0; i < nums.size(); ++i) {
    int first = 0, last = ans.size();
    while (first < last) {
      int mid = first + (last - first) / 2;
      if (nums[ans[mid]] < nums[i])
        first = mid + 1;
      else
        last = mid;
    }
    if (first == (int)ans.size())
      ans.push_back(i);
    else if (nums[ans[first]] > nums[i])
      ans[first] = i;
  }
  return ans.size();
}
