int smallestDifference(vector<int> &A, vector<int> &B) {
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());

  int ans = INT_MAX;
  int i = 0, j = 0;
  while (i < (int)A.size() && j < (int)B.size()) {
    ans = min(ans, abs(A[i] - B[j]));
    if (A[i] > B[j])
      ++j;
    else if (A[i] < B[j])
      ++i;
    else
      return 0;
  }
  return ans;
}
