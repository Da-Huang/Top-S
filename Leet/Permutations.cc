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


// #version2
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
