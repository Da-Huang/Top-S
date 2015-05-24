// #redo
void __combinationSum3(int k, int n, int begin, vector<int> &v, vector<vector<int>> &ans) {
  if (k == 0) {
    if (n == 0) ans.push_back(v);
    return;
  }
  if (n < begin || begin > 9) return;

  __combinationSum3(k, n, begin+1, v, ans);
  v.push_back(begin);
  __combinationSum3(k-1, n-begin, begin+1, v, ans);
  v.pop_back();
}

vector<vector<int>> combinationSum3(int k, int n) {
  vector<vector<int>> ans;
  vector<int> v;
  __combinationSum3(k, n, 1, v, ans);
  return ans;
}
