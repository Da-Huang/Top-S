vector<vector<int>> permute(vector<int> &num, vector<bool> &selected, int len=0) {
  vector<vector<int>> res;
  const int N = num.size();
  if ( len >= N ) {
    res.push_back(vector<int>());
    return res;
  }
  for (int i = 0; i < N; i ++) {
    if ( !selected[i] ) {
      selected[i] = true;
      vector<vector<int>> subRes = permute(num, selected, len + 1);
      for (auto &item : subRes) {
        item.insert(item.begin(), num[i]);
        res.push_back(item);
      }
      selected[i] = false;
    }
  }
  return res;
}

vector<vector<int> > permute(vector<int> &num) {
  vector<bool> selected(num.size(), false);
  return permute(num, selected);
}


// #redo
// #version2: for duplicate cases
void __permute(vector<int> &nums, size_t n, int last, vector<bool> &visited, vector<int> &v, vector<vector<int>> &ans) {
  if (n == nums.size()) {
    ans.push_back(v);
    return;
  }
  size_t begin = 0;
  while (begin < nums.size()) {
    if (visited[begin]) {
      ++ begin;
      continue;
    }
    size_t end = begin + 1;
    while (end < nums.size() && nums[begin] == nums[end]) ++ end;
    if (last != end) {
      for (size_t i = begin; i < end; ++ i) {
        visited[i] = true;
        v.push_back(nums[i]);
        __permute(nums, n + i - begin + 1, end, visited, v, ans);
      }
      for (size_t i = begin; i < end; ++ i) {
        visited[i] = false;
        v.pop_back();
      }
    }
    begin = end;
  }
}

vector<vector<int>> permute(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  vector<bool> visited(nums.size(), false);
  vector<int> v;
  vector<vector<int>> ans;
  __permute(nums, 0, -1, visited, v, ans);
  return ans;
}


// #version3
void __permute(vector<int> &nums, size_t n, vector<bool> &visited, vector<int> &v, vector<vector<int>> &ans) {
  if (n == nums.size()) {
    ans.push_back(v);
    return;
  }

  for (size_t i = 0; i < nums.size(); ++ i) {
    if (!visited[i]) {
      visited[i] = true;
      v.push_back(nums[i]);
      __permute(nums, n+1, visited, v, ans);
      visited[i] = false;
      v.pop_back();
    }
  }
}

vector<vector<int>> permute(vector<int>& nums) {
  vector<bool> visited(nums.size(), false);
  vector<int> v;
  vector<vector<int>> ans;
  __permute(nums, 0, visited, v, ans);
  return ans;
}
