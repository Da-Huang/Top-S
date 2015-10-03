void __addOperators(const string &num, string &item, vector<string> &ans, long long target, long long last, long long right, int begin) {
  if (begin == num.size()) {
    if (target == right * last) {
      ans.push_back(item);
    }
    return;
  }

  if (last) {
    item.push_back(num[begin]);
    __addOperators(num, item, ans, target, last * 10 + (num[begin] - '0'), right, begin + 1);
    item.pop_back();
  }

  item.push_back('+');
  item.push_back(num[begin]);
  __addOperators(num, item, ans, target - right * last, num[begin] - '0', 1, begin + 1);
  item.pop_back();
  item.pop_back();

  item.push_back('-');
  item.push_back(num[begin]);
  __addOperators(num, item, ans, target - right * last, num[begin] - '0', -1, begin + 1);
  item.pop_back();
  item.pop_back();

  item.push_back('*');
  item.push_back(num[begin]);
  __addOperators(num, item, ans, target, num[begin] - '0', right * last, begin + 1);
  item.pop_back();
  item.pop_back();
}

vector<string> addOperators(string num, int target) {
  if (num.empty()) return {};
  string item = {num[0]};
  vector<string> ans;
  __addOperators(num, item, ans, target, num[0] - '0', 1, 1);
  return ans;
}
