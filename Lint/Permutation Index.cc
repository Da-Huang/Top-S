// #redo
long long permutationIndex(vector<int>& A) {
  vector<int> B = A;
  sort(B.begin(), B.end());
  vector<bool> visited(B.size());
  long long BASE[A.size()];
  BASE[0] = 1;
  for (int i = 1; i < (int)A.size(); ++i) BASE[i] = BASE[i - 1] * (i + 1);
  long long ans = 0;
  for (int i = 0; i < (int)A.size() - 1; ++i) {
    int rank = 0;
    int j;
    for (j = 0; j < (int)A.size(); ++j) {
      if (B[j] == A[i]) break;
      if (!visited[j]) ++rank;
    }
    visited[j] = true;
    ans += rank * BASE[(int)A.size() - 2 - i];
  }
  return ans + 1;
}
