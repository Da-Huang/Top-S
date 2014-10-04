int __twoSumClosest(vector<int> &num, int first, int target) {
  int last = (int) num.size() - 1;
  int res = num[first] + num[last];
  while ( first < last ) {
    int subRes = num[first] + num[last];
    if ( abs(target - res) > abs(target - subRes) ) {
      res = subRes;
    }
    if ( num[first] + num[last] > target ) last --;
    else if ( num[first] + num[last] < target ) first ++;
    else return target;
  }
  return res;
}

int threeSumClosest(vector<int> &num, int target) {
  sort(num.begin(), num.end());
  const int N = num.size();
  assert(N >= 3);
  int res = num[0] + __twoSumClosest(num, 1, target - num[0]);
  for (int i = 1; i + 2 < N; i ++) {
    int subRes = num[i] + __twoSumClosest(num, i + 1, target - num[i]);
    if ( abs(target - res) > abs(target - subRes) ) {
      res = subRes;
    }
  }
  return res;
}

