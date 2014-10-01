vector<vector<int>> twoSum(vector<int> &num, int first, int last, int target) {
  vector<vector<int>> res;
  while ( first < last ) {
    if ( num[first] + num[last] > target ) last --;
    else if ( num[first] + num[last] < target ) first ++;
    else {
      res.push_back({num[first], num[last]});
      int oldFirst = first ++;
      while ( first < last && num[first] == num[oldFirst] ) first ++;
    }
  }
  return res;
}

vector<vector<int> > threeSum(vector<int> &num) {
  vector<vector<int>> res;
  sort(num.begin(), num.end());
  const int N = num.size();
  int begin = 0;
  while ( begin < N ) {
    vector<vector<int>> subRes = twoSum(num, begin + 1, N - 1, -num[begin]);
    for (auto &item : subRes) {
      item.insert(item.begin(), num[begin]);
      res.push_back(item);
    }
    int oldBegin = begin ++;
    while ( begin < N && num[begin] == num[oldBegin] ) begin ++;
  }
  return res;
}

