vector<vector<int>> twoSum(vector<int> &num, int first, int target) {
  int last = (int) num.size() - 1;
  vector<vector<int>> res;
  while ( first < last ) {
    if ( num[first] + num[last] == target ) {
      res.push_back(vector<int>{num[first], num[last]});
    }
    if ( num[first] + num[last] <= target ) {
      int firstOld = first ++;
      while ( first < last && num[first] == num[firstOld] ) first ++;
    } else {
      int lastOld = last --;
      while ( first < last && num[last] == num[lastOld] ) last --;
    }
  }
  return res;
}

vector<vector<int> > fourSum(vector<int> &num, int target) {
  const int N = num.size();
  vector<vector<int>> res;
  if ( N < 4 ) return res;
  sort(num.begin(), num.end());
  int iBegin = 0;
  while ( iBegin + 3 < N ) {
    int jBegin = iBegin + 1;
    while ( jBegin + 2 < N ) {
      vector<vector<int>> subRes = twoSum(num, jBegin + 1, target - num[iBegin] - num[jBegin]);
      for (auto &v : subRes) {
        res.push_back(vector<int>({num[iBegin], num[jBegin], v[0], v[1]}));
      }
      int jBeginOld = jBegin ++;
      while ( jBegin + 2 < N && num[jBegin] == num[jBeginOld] ) jBegin ++;
    }
    int iBeginOld = iBegin ++;
    while ( iBegin + 3 < N && num[iBegin] == num[iBeginOld] ) iBegin ++;
  }
  return res;
}

