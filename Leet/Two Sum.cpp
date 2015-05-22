// #redo
vector<int> twoSum(vector<int>& nums, int target) {
  const int N = nums.size();
  if (N < 2) return {};

  vector<int> idxs(N);
  for (int i = 0; i < N; ++ i) idxs[i] = i;
  sort(idxs.begin(), idxs.end(), [&nums](int i, int j) {
      return nums[i] < nums[j];
      });
  int i = 0, j = N - 1;
  while (i < j) {
    if (nums[idxs[i]] + nums[idxs[j]] > target) -- j;
    else if (nums[idxs[i]] + nums[idxs[j]] < target) ++ i;
    else return {min(idxs[i],idxs[j]) + 1, max(idxs[i],idxs[j]) + 1};
  }
  return {};
}

// #solution2
vector<int> twoSum(vector<int>& nums, int target) {
  const int N = nums.size();
  if (N < 2) return {};

  unordered_map<int, int> mapping;
  for (int i = 0; i < N; ++ i) {
    auto it = mapping.find(target - nums[i]);
    if (it != mapping.end()) return {it->second + 1, i + 1};
    mapping[nums[i]] = i;
  }
  return {};
}
