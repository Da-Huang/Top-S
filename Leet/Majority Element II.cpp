// #redo
vector<int> majorityElement(vector<int>& nums) {
  int val0, val1;
  int count0 = 0, count1 = 0;
  for (int num : nums) {
    if (count0 && val0 == num) ++count0;
    else if (count1 && val1 == num) ++count1;
    else if (count0 == 0) {
      ++count0;
      val0 = num;
    } else if (count1 == 0) {
      ++count1;
      val1 = num;
    } else {
      --count0;
      --count1;
    }
  }
  vector<int> ans;

  count0 = count1 = 0;
  for (int num : nums) {
    if (num == val0) ++count0;
    else if (num == val1) ++count1;
  }

  if (count0 > (int) nums.size() / 3) ans.push_back(val0);
  if (count1 > (int) nums.size() / 3) ans.push_back(val1);
  return ans;
}
