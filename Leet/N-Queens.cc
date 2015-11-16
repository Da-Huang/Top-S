vector<vector<string>> __solve(int n, 
    unsigned long long attackL, unsigned long long attackR, unsigned long long attackV, int begin=0) {
  vector<vector<string>> res;
  if ( begin == n ) {
    res.push_back(vector<string>());
    return res;
  }
  unsigned long long attack = attackL | attackR | attackV;
  for (int i = 0; i < n; i ++) {
    if ( (attack & (1 << i)) == 0 ) {
      unsigned long long nextAttackL = attackL;
      unsigned long long nextAttackR = attackR;
      unsigned long long nextAttackV = attackV;
      nextAttackL |= 1 << i;
      nextAttackL <<= 1;
      nextAttackR |= 1 << i;
      nextAttackR >>= 1;
      nextAttackV |= 1 << i;
      vector<vector<string>> subRes = __solve(n, nextAttackL, nextAttackR, nextAttackV, begin + 1);
      for (auto &v : subRes) {
        v.insert(v.begin(),string(n, '.'));
        v[0][i] = 'Q';
        res.push_back(v);
      }
    }
  }
  return res;
}

vector<vector<string> > solveNQueens(int n) {
  return __solve(n, 0, 0, 0);
}


// #redo
// #version2
void __solveQueens(int n, int begin, int x[], vector<vector<string>> &ans) {
  if (begin == n) {
    vector<string> item(n, string(n, '.'));
    for (int i = 0; i < n; ++ i) item[x[i]][i] = 'Q';
    ans.push_back(item);
    return;
  }
  vector<bool> able(n, true);
  for (int i = 0; i < begin; ++ i) {
    able[x[i]] = false;
    if (x[i] + (begin - i) < n) able[x[i] + (begin - i)] = false;
    if (x[i] - (begin - i) >= 0) able[x[i] - (begin - i)] = false;
  }
  for (int i = 0; i < n; ++ i) {
    if (able[i]) {
      x[begin] = i;
      __solveQueens(n, begin + 1, x, ans);
    }
  }
}

vector<vector<string> > solveNQueens(int n) {
  int x[n];
  vector<vector<string>> ans;
  __solveQueens(n, 0, x, ans);
  return ans;
}
