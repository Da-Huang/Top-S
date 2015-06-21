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


// #version2
vector<string> generateParenthesis(int n) {
  vector<string> ans;
  if (n == 0) return ans;
  if (n == 1) {
    ans.push_back("()");
    return ans;
  }
  auto subAns = generateParenthesis(n - 1);
  for (string &item : subAns) {
    ans.push_back(item + "()");
    ans.push_back("(" + item + ")");
  }
  for (int i = 1; i < n - 1; ++ i) {
    auto subAns1 = generateParenthesis(i);
    auto subAns2 = generateParenthesis(n - 1 - i);
    for (string &item1 : subAns1) {
      for (string &item2 : subAns2) {
        ans.push_back(item1 + "(" + item2 + ")");
      }
    }
  }
  return ans;
}


// #version3
// NOTE: take n = 0 as ""
vector<string> generateParenthesis(int n) {
  vector<string> ans;
  if (n == 0) {
    ans.push_back("");
    return ans;
  }
  for (int i = 0; i < n; ++ i) {
    auto subAns1 = generateParenthesis(i);
    auto subAns2 = generateParenthesis(n - 1 - i);
    for (string &item1 : subAns1) {
      for (string &item2 : subAns2) {
        ans.push_back(item1 + "(" + item2 + ")");
      }
    }
  }
  return ans;
}


// #version4
// NOTE: most efficient
void __generateParenthesis(int n, int needRight, string &v, vector<string> &ans) {
  if (n == 0) {
    ans.push_back(v + string(needRight, ')'));
    return;
  }

  v.push_back('(');
  __generateParenthesis(n - 1, needRight + 1, v, ans);
  if (needRight) {
    v.back() = ')';
    __generateParenthesis(n, needRight - 1, v, ans);
  }
  v.pop_back();
}

vector<string> generateParenthesis(int n) {
  vector<string> ans;
  if (n == 0) return ans;
  string v;
  __generateParenthesis(n, 0, v, ans);
  return ans;
}
