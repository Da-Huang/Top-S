// #redo
string multiply(string num1, string num2) {
  if (num1 == "0" || num2 == "0") return "0";
  reverse(num1.begin(), num1.end());
  reverse(num2.begin(), num2.end());
  string ans;
  for (size_t i = 0; i < num2.size(); ++ i) {
    int c = 0;
    size_t k = i;
    for (size_t j = 0; j < num1.size(); ++ j) {
      int p;
      if (k < ans.size()) {
        p = (num1[j] - '0') * (num2[i] - '0') + ans[k] - '0' + c;
        ans[i + j] = p % 10 + '0';
      } else {
        p = (num1[j] - '0') * (num2[i] - '0') + c;
        ans.push_back(p % 10 + '0');
      }
      c = p / 10;
      ++ k;
    }
    while (k < ans.size() && c) {
      int p = ans[k] - '0' + c;
      ans[k] = p % 10 + '0';
      c = p / 10;
      ++ k;
    }
    if (c) ans.push_back(c + '0');
  }
  reverse(ans.begin(), ans.end());
  return ans;
}
