// #redo
string binaryRepresentation(string n) {
  while (n.size() > 1 && n.back() == '0') n.pop_back();
  if (!n.empty() && n.back() == '.') n.pop_back();
  size_t point_index = n.find(".");
  if (point_index == string::npos) point_index = n.size();
  size_t begin = 0;
  bool is_negative = false;
  if (n.front() == '-') {
    is_negative = true;
    ++begin;
  }
  string ans;
  while (begin < point_index) {
    ans.push_back(((n[point_index - 1] - '0') & 1) + '0');
    int c = 0;
    for (size_t i = begin; i < point_index; ++i) {
      int p = n[i] - '0' + c;
      n[i] = p / 2 + '0';
      c = (p % 2) * 10;
    }
    if (n[begin] == '0') ++begin;
  }
  if (is_negative) ans.push_back('-');
  reverse(ans.begin(), ans.end());
  if (point_index == n.size()) return ans;
  ans.push_back('.');

  begin = point_index + 1;
  while (begin < n.size()) {
    if (n.back() != '5') return "ERROR";
    ans.push_back(n[begin] >= '5' ? '1' : '0');
    int c = 0;
    for (size_t i = n.size() - 1; i >= begin; --i) {
      int p = (n[i] - '0') * 2 + c;
      n[i] = p % 10 + '0';
      c = p / 10;
    }
    n.pop_back();
  }
  return ans;
}
