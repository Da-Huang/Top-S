int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
  const int N = gas.size();
  int ans = 0;
  int sum = 0;
  for (int i = 0; i < 2 * N; ++ i) {
    sum += gas[i%N] - cost[i%N];
    if (sum < 0) {
      ans = i + 1;
      sum = 0;

    } else if (i - ans + 1 == N) {
      return ans;
    }
  }
  return -1;
}
