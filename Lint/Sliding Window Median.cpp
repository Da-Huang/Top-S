// #redo
void __adjust(multiset<int> &set1, multiset<int> &set2) {
  if (set2.size() > set1.size()) {
    set1.insert(*set2.begin());
    set2.erase(set2.begin());
  } else if (set1.size() > set2.size() + 1) {
    set2.insert(*prev(set1.end()));
    set1.erase(prev(set1.end()));
  }
}

void __push(multiset<int> &set1, multiset<int> &set2, int val) {
  if (set1.empty()) {
    set1.insert(val);
  } else if (val <= *prev(set1.end())) {
    set1.insert(val);
  } else {
    set2.insert(val);
  }
  __adjust(set1, set2);
}

void __pop(multiset<int> &set1, multiset<int> &set2, int val) {
  auto it = set1.find(val);
  if (it != set1.end()) {
    set1.erase(it);
  } else {
    set2.erase(set2.find(val));
  }
  __adjust(set1, set2);
}

vector<int> medianSlidingWindow(vector<int> &nums, int k) {
  vector<int> ans;
  multiset<int> set1, set2;
  for (int i = 0; i < (int)nums.size(); ++i) {
    __push(set1, set2, nums[i]);
    if (i >= k - 1) {
      ans.push_back(*prev(set1.end()));
      __pop(set1, set2, nums[i - (k - 1)]);
    }
  }
  return ans;
}
