vector<int> plusOne(vector<int> &digits) {
  reverse(digits.begin(), digits.end());
  vector<int> res;
  const int N = digits.size();
  if ( N == 0 ) {
    res.push_back(1);
    return res;
  }
  int i = 0;
  int c = 1;
  while ( i < N ) {
    int part = digits[i] + c;
    digits[i] = part % 10;
    c = part / 10;
    i ++;
  }
  if ( c ) digits.push_back(1);
  reverse(digits.begin(), digits.end());
  return digits;
}

