string simplifyPath(string path) {
  list<string> stk;
  const int N = path.length();
  int begin = 0;
  while ( begin < N && path[begin] == '/' ) begin ++;
  while ( begin < N ) {
    int end = begin + 1;
    while ( end < N && path[end] != '/' ) end ++;
    string item = path.substr(begin, end - begin);
    if ( item == ".." ) {
      if ( !stk.empty() ) stk.pop_back();

    } else if ( item != "." ) {
      stk.push_back(item);
    }
    while ( end < N && path[end] == '/' ) end ++;
    begin = end;
  }
  string res;
  for (auto &item : stk) {
    res += "/";
    res += item;
  }
  return res.length() == 0 ? "/" : res;
}

