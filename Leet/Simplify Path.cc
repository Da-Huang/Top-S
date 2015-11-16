// #redo
string simplifyPath(string path) {
  vector<string> stk;
  size_t i = 1;
  while (i < path.size()) {
    size_t j = i;
    while (j < path.size() && path[j] != '/') ++ j;
    string item = path.substr(i, j - i);
    if (item == "..") {
      if (!stk.empty()) stk.pop_back();
    } else if (!item.empty() && item != ".") stk.push_back(item);
    i = j + 1;
  }
  if (stk.empty()) return "/";
  string ans;
  for (string &item : stk) ans += "/" + item;
  return ans;
}
