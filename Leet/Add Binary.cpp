string addBinary(string a, string b) {
  const int N = a.length();
  const int M = b.length();
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  string res;
  int i = 0, j = 0;
  int c = 0;
  while ( i < N && j < M ) {
    int p = a[i] - '0' + b[j] - '0' + c;
    res.push_back(p % 2 + '0');
    c = p / 2;
    i ++; j ++;
  }
  while ( i < N ) {
    int p = a[i] - '0' + c;
    res.push_back(p % 2 + '0');
    c = p / 2;
    i ++;
  }
  while ( j < M ) {
    int p = b[j] - '0' + c;
    res.push_back(p % 2 + '0');
    c = p / 2;
    j ++;
  }
  if ( c ) res.push_back(c + '0');
  reverse(res.begin(), res.end());
  return res;
}

