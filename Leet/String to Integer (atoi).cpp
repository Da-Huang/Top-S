int atoi(const char *str) {
  int i = 0;
  while ( str[i] == ' ' ) i ++;
  bool isNegative = false;
  if ( str[i] == '-' ) {
    isNegative = true;
    i ++;

  } else if ( str[i] == '+' ) {
    i ++;
  }

  int res = 0;
  while ( isdigit(str[i]) ) {
    int d = str[i] - '0';
    if ( res < (INT_MIN + d) / 10 ) {
      return isNegative ? INT_MIN : INT_MAX;
    }
    res = res * 10 - d;
    i ++;
  }
  if ( isNegative ) return res;
  if ( res == INT_MIN ) return INT_MAX;
  return -res;
}

