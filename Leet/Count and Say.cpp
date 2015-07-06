string countAndSay(int n) {
  string res = "1";
  if ( n == 1 ) return res;
  for (int i = 2; i <= n; i ++) {
    string next;
    int begin = 0;
    const int N = res.size();
    while ( begin < N ) {
      int end = begin + 1;
      while ( end < N && res[end] == res[begin] ) end ++;
      next += to_string(end - begin);
      next.push_back(res[begin]);
      begin = end;
    }
    res = next;
  }
  return res;
}


// #redo
// #version2
string countAndSay(int n) {
  string ans = "1";
  for (int i = 1; i < n; ++ i) {
    string tmp;
    int j = 0;
    for (int k = 1; k <= (int) ans.size(); ++ k) {
      if (k == (int) ans.size() || ans[k] != ans[j]) {
        tmp += to_string(k - j) + ans[j];
        j = k;
      }
    }
    ans = move(tmp);
  }
  return ans;
}
