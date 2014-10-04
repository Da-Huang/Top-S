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

