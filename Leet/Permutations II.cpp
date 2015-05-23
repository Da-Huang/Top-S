vector<vector<int>> __permute(vector<int> &num, vector<bool> &visited, int lastIndex=-1, int count=0) {
  const int N = num.size();
  vector<vector<int>> res;
  if ( count == N ) {
    res.push_back(vector<int>());
    return res;
  }

  int begin = 0;
  while ( begin < N ) {
    if ( visited[begin] || (lastIndex >= 0 && num[begin] == num[lastIndex]) ) {
      begin ++;

    } else {
      int end = begin;
      while ( end < N && num[end] == num[begin] ) {
        visited[end] = true;
        end ++;
        vector<vector<int>> subRes = __permute(num, visited, begin, count + end - begin);
        for (auto &v : subRes) {
          v.insert(v.begin(), end - begin, num[begin]);
          res.push_back(v);
        }
      }
      fill(visited.begin() + begin, visited.begin() + end, false);
      begin = end;
    }
  }
  return res;
}

vector<vector<int> > permuteUnique(vector<int> &num) {
  sort(num.begin(), num.end());
  vector<bool> visited(num.size(), false);
  return __permute(num, visited);
}


// #redo
// #version2
void __permute(vector<int> &nums, size_t n, size_t last, vector<bool> &visited, vector<int> &v, vector<vector<int>> &ans) {
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

vector<vector<int>> permuteUnique(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  vector<bool> visited(nums.size(), false);
  vector<int> v;
  vector<vector<int>> ans;
  __permute(nums, 0, -1, visited, v, ans);
  return ans;
}
