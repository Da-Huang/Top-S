vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
  sort(A.begin(), A.end());
  vector<int> ans;
  for (int query : queries) {
    ans.push_back(distance(A.begin(), lower_bound(A.begin(), A.end(), query)));
  }
  return ans;
}
