int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
  const int N = gas.size();
  if ( N == 0 ) return 0;
  int begin = 0;
  int cur = 0;
  for (int i = 0; i < 2 * N - 1; i ++) {
    cur += gas[i%N] - cost[i%N];
    if ( cur >= 0 ) {
      if ( i - begin + 1 == N ) return begin;

    } else {
      begin = i + 1;
      cur = 0;
    }
  }
  return -1;
}

