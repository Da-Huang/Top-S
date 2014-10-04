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

