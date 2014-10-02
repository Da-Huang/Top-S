vector<string> generateParenthesis(int n) {
  vector<string> res[n + 1];
  res[0] = vector<string>(1, "");
  for (int i = 1; i <= n; i ++) {
    // i is the len
    for (int j = 0; j < i; j ++) {
      vector<string> &res1 = res[j];
      vector<string> &res2 = res[i - j - 1];
      for (auto &item1 : res1) {
        for (auto &item2 : res2) {
          string item = item1;
          item += "(";
          item += item2;
          item += ")";
          res[i].push_back(item);
        }
      }
    }
  }
  return res[n];
}

