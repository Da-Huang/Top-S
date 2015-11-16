vector<int> subarraySum(vector<int> nums){
  unordered_map<int, int> mapping;
  int sum = 0;
  mapping[sum] = 0;
  for (int i = 0; i < (int)nums.size(); ++i) {
    sum += nums[i];
    if (mapping.find(sum) != mapping.end()) {
      return {mapping[sum], i};
    }
    mapping[sum] = i + 1;
  }
  return {};
}
