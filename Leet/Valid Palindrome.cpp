bool isPalindrome(string s) {
  const int N = s.length();
  int first = 0, last = N - 1;

  while ( first < last && !isalnum(s[first]) ) first ++;
  while ( first < last && !isalnum(s[last]) ) last --;
  while ( first < last ) {
    char c1 = isupper(s[first]) ? tolower(s[first]) : s[first];
    char c2 = isupper(s[last]) ? tolower(s[last]) : s[last];
    if ( c1 != c2 ) return false;
    first ++; last --;
    while ( first < last && !isalnum(s[first]) ) first ++;
    while ( first < last && !isalnum(s[last]) ) last --;
  }
  return true;
}

