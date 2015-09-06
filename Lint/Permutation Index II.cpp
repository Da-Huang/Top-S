// #redo
long long permutationIndexII(vector<int>& A) {
  vector<bool> visited(A.size());
  long long FACTORIAL[A.size()];
  FACTORIAL[0] = 1;
  for (int i = 1; i < (int)A.size(); ++i) FACTORIAL[i] = FACTORIAL[i - 1] * i;
  map<int, int> MAP;
  for (int num : A) ++MAP[num];
  long long REDUCE = 1;
  for (auto& p : MAP) REDUCE *= FACTORIAL[p.second];

  long long ans = 0;
  for (int i = 0; i < (int)A.size(); ++i) {
    auto it = MAP.begin();
    for (; it != MAP.end(); ++it) {
      if (it->first == A[i]) break;
      ans += FACTORIAL[(int)A.size() - i - 1] / (REDUCE / it->second);
    }
    REDUCE /= it->second;
    if (--it->second == 0) MAP.erase(it);
  }
  return ans + 1;
}
