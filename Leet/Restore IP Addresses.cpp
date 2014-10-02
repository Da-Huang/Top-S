// Redo
vector<string> restoreIpAddresses(string s) {
  vector<string> res;
  const int N = s.length();
  for (int i = max(0, N - 10); i + 3 < N && i < 3; i ++) {
    const int a = stoi(s.substr(0, i + 1));
    if ( s[0] == '0' && i + 1 > 1 || a > 255 ) break;
    for (int j = max(i + 1, N - 7); j + 2 < N && j < i + 4; j ++) {
      const int b = stoi(s.substr(i + 1, j - i));
      if ( s[i + 1] == '0' && j - i > 1 || b > 255 ) break;
      for (int k = max(j + 1, N - 4); k + 1 < N && k < j + 4; k ++) {
        const int c = stoi(s.substr(j + 1, k - j));
        if ( s[j + 1] == '0' && k - j > 1 || c > 255 ) break;
        const int d = stoi(s.substr(k + 1));
        if ( !(s[k + 1] == '0' && N - k - 1 > 1)  && d <= 255 ) {
          string item = to_string(a);
          item += ".";
          item += to_string(b);
          item += ".";
          item += to_string(c);
          item += ".";
          item += to_string(d);
          res.push_back(item);
        }
      }
    }
  }
  return res;
}

