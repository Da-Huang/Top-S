bool isNumber(const char *s) {
  int N = strlen(s);
  int first = 0;
  while ( N > 0 && s[N - 1] == ' ' ) N --;
  while ( first < N && s[first] == ' ' ) first ++;
  if ( first < N && (s[first] == '+' || s[first] == '-') ) first ++;

  bool hasNumber = false;
  while ( first < N && isdigit(s[first]) ) {
    first ++;
    hasNumber = true;
  }
  if ( first == N ) return hasNumber;

  if ( s[first] == '.' ) {
    first ++;
    while ( first < N && isdigit(s[first]) ) {
      first ++;
      hasNumber = true;
    }
  }
  if ( !hasNumber ) return false;
  if ( first == N ) return true;

  if ( tolower(s[first]) != 'e' ) return false;
  first ++;

  if ( first < N && (s[first] == '+' || s[first] == '-') ) first ++;
  hasNumber = false;
  while ( first < N && isdigit(s[first]) ) {
    first ++;
    hasNumber = true;
  }
  return first == N && hasNumber;
}

